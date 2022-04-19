#include <bits/stdc++.h>
using namespace std;

vector< pair < int, pair<int,int> > > graph[1010];
vector<pair<int,int> > nohighway[1010];
int dis[20020];
list<int> Q;
int ans=1e9;

// int shortestpath(int s,int t);
int shortestpathnohigh(int s,int t);

int main(void){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w,t;
        cin >> u >> v >> w >> t;
        u--;v--;
        graph[u].push_back({v,{w,t}});
        graph[v].push_back({u,{w,t}});
        if(t==0){
            nohighway[u].push_back({v,w});
            nohighway[v].push_back({u,w});
        }
    }

    //find least shortest path from start to highway + shortest path from highway to finish
    //for every started highway
    for(int i=0;i<n;i++){
        for(auto it=graph[i].begin();it!=graph[i].end();it++){
            int tmpans=0;
            int v=it->first;
            int w=it->second.first;
            int t=it->second.second;
            if(t==1){ //find way from start to u(i) to v and v to n-1 (w = u to v)
                int start_to_u = shortestpathnohigh(0,i);
                int v_to_end = shortestpathnohigh(v,n-1);
                printf("%d to %d + %d to %d +%d to %d\n",1,i+1,i+1,v+1,v+1,n);
                //if there is no path from 0 to u or v to n-1
                if(start_to_u == 1e9 || v_to_end == 1e9){
                    tmpans = 1e9;
                }
                else{
                    tmpans = start_to_u+w+v_to_end;
                    if(tmpans < ans){
                        ans = tmpans;
                    }
                }
                //printf("  %d + %d + %d = %d\n",w,start_to_u,v_to_end,tmpans);
            }
        }
    }

    if(ans==1e9){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}

int shortestpathnohigh(int s, int t){
    //reset
    for(int i=0;i<20020;i++){
        dis[i]=1e9;
    }
    dis[s]=0;
    Q.push_back(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        for(auto it = nohighway[u].begin();it!=nohighway[u].end();it++){
            int v = it->first;
            int w = it->second;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                Q.push_back(v);
            }
        }
    }
    return dis[t];
}


// int shortestpath(int s,int t){
//     //reset
//     for(int i=0;i<20020;i++){
//         dis[i]=1e9;
//     }
//     dis[s]=0;
//     Q.push_back(s);
//     while(!Q.empty()){
//         int u = Q.front();
//         Q.pop_front();
//         for(auto it = graph[u].begin();it!=graph[u].end();it++){
            
//         }
//     }
// }