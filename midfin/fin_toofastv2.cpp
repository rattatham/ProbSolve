#include <bits/stdc++.h>
using namespace std;
//dis[node][0] = dis from start to node that hasn't pass highway
//dis[node][1] = highway passed
int dis[1010][2];
int ans=1e9;
vector< pair < int, pair<int,int> > > graph[1010];
list<pair<int,int> > Q;


int main(void){
    for(int i=0;i<1010;i++){
        for(int j=0;j<2;j++){
            dis[i][j]=1e9;
        }
    }

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w,t;
        cin >> u >> v >> w >> t;
        u--;v--;
        graph[u].push_back({v,{w,t}});
        graph[v].push_back({u,{w,t}});
    }

    //start from 0
    dis[0][0]=0;
    dis[0][1]=0;
    Q.push_back({0,0});
    while(!Q.empty()){
        int u = Q.front().first;
        int from_highway = Q.front().second;
        Q.pop_front();
        //printf("from %d(ishighway:%d)\n",u+1,from_highway);
        for(auto it=graph[u].begin();it!=graph[u].end();it++){
            int v = it->first;
            int w = it->second.first;
            int t = it->second.second;
            //printf("  to %d",v+1);
            //if it passed highway we don't go acroos highway anymore
            if(from_highway == 1 && t == 1){
                //printf(" pass\n");
                continue;
            }

            //if this is passed highway then we only + dis[v][1] 
            //(dis from start to v that passed highway)
            else if(from_highway == 1 && t == 0){
                if(dis[v][from_highway] > w+dis[u][from_highway]){
                    //printf(" updated dis[%d][%d]\n",v+1,from_highway);
                    dis[v][from_highway] = w+dis[u][from_highway];
                    Q.push_back({v,t});
                }
            }

            //not from highway it can go everywhere
            //t=1=highway t=0=normal
            else if(from_highway == 0){
                if(dis[v][t] > w+dis[u][from_highway]){
                    //printf(" updated dis[%d][%d]\n",v+1,t);
                    dis[v][t] = w+dis[u][from_highway];
                    Q.push_back({v,t});
                }
            }
            
        }
    }


    for(int i=0;i<2;i++){
        if(dis[n-1][i] < ans){
            ans = dis[n-1][i];
        }
    }
    
    if(ans==1e9){
        cout << -1;
    }
    else{
        cout << ans;
    }
    return 0;
}