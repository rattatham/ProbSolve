#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> graph[100010];
int visited[100010];
int color[100010];
list<int> Q;
void clear(int ,int);
int check(int ,int);
int tmp=0;
int ans=0;

int main(){
    int count = 1;
    for(int i=0;i<100010;i++){
        visited[i] = 0;
        color[i] = -1;
    }
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if(!visited[u]){
            tmp = check(u,v);
        }
        else if(!visited[v]){
            tmp = check(v,u);
        }
        else{
            tmp = check(u,v);
            if(!tmp){
                //printf("at %d(%d) %d(%d)\n",u+1,color[u],color[v],v+1);
                count = 0;
                break;
            }
        }
        ans+=count;
    }
    cout << ans;
}

void clear(int u,int v){
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    //cout << u << endl;
    color[u] = 0;
    Q.push_back(u);
    while(!Q.empty()){
        int s = Q.front();
        //printf("clear %d\n",s+1);
        Q.pop_front();
        for(auto node : graph[s]){
            if(color[node] != -1 && node != u){
                color[node] = -1;
                Q.push_back(node);
            }
        }
    }
}

int check(int u,int v){
    if(color[u] == -1){
        if(color[v] == -1){
            color[u] = 0;
        }
        else{
            color[u] = (color[v]+1)%2;
        }
    }

    if(color[u] == color[v]){
        clear(u,v);
    }
    Q.push_back(u);
    while(!Q.empty()){
        int s = Q.front();
        Q.pop_front();
        visited[s] = 1;
        for(auto node : graph[s]){
            if(color[node] == color[s]){
                //printf("%d %d\n",s+1,node+1);
                return 0;
            }
            if(color[node] == -1){
                color[node] = (color[s]+1)%2;
            }
            if(!visited[node]){
                Q.push_back(node);
            }
        }
    }
    return 1;
}