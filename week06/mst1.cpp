#include <bits/stdc++.h>
using namespace std;

int parents[1010];
int ranks[1010];
vector<vector<int>> graph;
int find(int n);

int main(void){

    //getinput()
    int n,m,ans=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph.push_back({w,u,v});
    }

    //init()
    for(int i=0;i<n;i++){
        ranks[i]=1;
        parents[i]=-1;
    }
    sort(graph.begin(),graph.end());

    //for all edges
    for(auto it:graph){
        int w = it[0];
        int u = it[1];
        int v = it[2];

        //if u and v don't have same leader
        if(find(u)!=find(v)){
            ans+=w;
            //union them
            int pu = find(u);
            int pv = find(v);
            if(pu!=pv){
                if(ranks[pu]<ranks[pv]){
                    parents[pu] = pv;
                    ranks[pv]+=ranks[pu];
                }
                else{
                    parents[pv] = pu;
                    ranks[pu]+=pv;
                }
            }
        }
    }

    cout << ans;

    return 0;
}

int find(int n){
    if(parents[n]==-1)
        return n;
    n = parents[n];
    return find(n);
}