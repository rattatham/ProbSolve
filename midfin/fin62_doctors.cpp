#include <bits/stdc++.h>
using namespace std;

int R[100010];
vector<pair<int,int> > graph[100010];
list<int> Q;
void shortestpath(int s);
int dis[100010];
int ans=0;

int main(){

    for(int i=0;i<100010;i++){
        dis[i]=1e9;
    }

    int n,m,l;
    cin >> n >> m >> l;
    for(int i=1;i<=n;i++){
        cin >> R[i];
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }

    shortestpath(1);
    for(int i=2;i<=n;i++){
        //printf("dis[%d] = %d\n",i,dis[i]);
        if(l*dis[i]<dis[i]*R[i]){
            ans+=l*dis[i];
        }
        else{
            ans+=dis[i]*R[i];
        }
    }
    cout << ans;
}

void shortestpath(int s){
    Q.push_back(s);
    dis[s] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        for(auto it=graph[u].begin();it!=graph[u].end();it++){
            int v = it->second;
            int w =it->first;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                Q.push_back(v);
            }
        }
    }
}