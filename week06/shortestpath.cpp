#include <bits/stdc++.h>

#define MAX_INT 1e9
using namespace std;

vector<pair<int,int>> graph[100010];
list<int> q;
int dis[100010];
int N,M;

void shortestpath(int s);

int main(void){ 
    cin >> N >> M;
    //init()
    for(int i=0;i<N;i++){
        dis[i]=MAX_INT;
    }

    //get_input()
    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    //printgraph()
    /*for(int i=0;i<N;i++){
        cout << i;
        for(auto it=graph[i].begin();it!=graph[i].end();it++){
            int v = it->first;
            int w = it->second;
            cout << "->" << v << "(weighted:" << w << ") ";
        }
        cout << endl;
    }*/
    int s=0;
    shortestpath(s);
    /*for(int i=0;i<N;i++){
        cout << i+1 << ": " << dis[i] << endl;
    }*/
    cout << dis[N-1];
    return 0;
}

void shortestpath(int s){
    q.push_back(s);
    dis[s] = 0;
    while(!q.empty()){
        //cout << "loop" << endl;
        int u = q.front();
        q.pop_front();
        //cout << "traverse from :" << u << " to ";
        for(auto it=graph[u].begin();it!=graph[u].end();it++){
            int v = it->first;
            int w = it->second;
            //cout << v << " ";
            /*if(dis[v] == MAX_INT && dis[u]!=MAX_INT){
                dis[v] = dis[u]+w;
            }*/
            // if update we considered it again.
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                q.push_back(v);
            }
            //q.push_back(v);
        }
        //cout << endl;
    }
}
