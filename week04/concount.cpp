#include <bits/stdc++.h>
using namespace std;
const int MAX_N=100100;
int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];
int layer[MAX_N];
void read_input(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    deg[i]=0;
  }
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

bool discovered[MAX_N];
void init(){
  for(int i=0;i<n;i++){
    discovered[i]=false;
  }
}

void bfs(int s){
  discovered[s]=true;
  layer[s]=0; // parent[s]=-1;
  list<int> current_layer;
  list<int> next_layer;
  current_layer.push_back(s);
  while(!current_layer.empty()){
    for(auto it=current_layer.begin();it!=current_layer.end();it++){
      int u=*it;
      for(int d=0;d<deg[u];d++){
        int v=adj[u][d];
          if(!discovered[v]){
            next_layer.push_back(v);
            discovered[v]=true;
            layer[v]=layer[u]+1; //parent[v]=u;
          }
        }
      }
      current_layer = next_layer;
      next_layer.clear();
  }
}

int main(void){
  read_input();
  init();
  int concount=0;
  for(int s=0;s<n;s++){
      if(!discovered[s]){
          bfs(s);
          concount++;
      }
  }
  cout << concount;
}