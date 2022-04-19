#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
list<int> Q;
int visited[100010];
void bfs(int s);
int n,m,k;
int group[100010];



int main(){
    //init()
    for(int i=0;i<n;i++){
        visited[i]=0;
        group[i]=-1;
    }

    //getinput()
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //bfs
    for(int i=0;i<n;i++){
        if(!visited[i]){
            group[i]=i;
            bfs(i);
        }
    }

    for(int i=0;i<k;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        if(group[u]==group[v]){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }

}

void bfs(int s){
    Q.push_back(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        if(!visited[u]){
            group[u]=s;
            visited[u]=1;
            for(auto it = graph[u].begin();it!=graph[u].end();it++){
                Q.push_back(*it);
            }
        }
    }
}