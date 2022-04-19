#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> village[100100];
queue<pair<int,int>> save;
int dist[100100];
int tmp[100100];
int n,m,s,t;

void addEdge(int m){
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        village[u].push_back(v);
        village[v].push_back(u);
    }
}

void addStorage(int chk,int s){
    if(chk){
        for(int i=0;i<s;i++){
            int storagenum;
            cin >> storagenum;
            dist[storagenum]=0;
            save.push({storagenum,0});
        }
    }
}


void bfs(int chk){
    if(chk){
        while(!save.empty()){
            int walk=save.front().first;
            int dis=save.front().second;
            save.pop();
            for(int j=0;j<village[walk].size();j++){
                int factory=village[walk][j];
                if(walk+1<dist[factory]){
                    dist[factory]=walk+1;
                    save.push({factory,dist[factory]});
                }
            }
        }
    }
}

void res(int chk,int t){
    if(chk){
        for(int i=0;i<t;i++){
            int fac;
            cin >> fac;
            cout << dist[fac] << endl;
        }
    }
}

int main(void){
    int chk=1;
    cin >> n >> m >> s >> t;
    for(int i=1;i<n+1;i++){
        dist[i]=1e9;
    }
    addEdge(m);
    addStorage(chk,s);
    bfs(chk);
    res(chk,t);
    return 0;
}