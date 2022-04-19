#include <bits/stdc++.h>
using namespace std;

int parents[210];
vector<pair<int,pair<int,int> > > graph;
int find(int);


int main(){

    int n,w;
    cin >> n >> w;

    while(w--){
        
        //getinput
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        graph.push_back({w,{u,v}});
        sort(graph.begin(),graph.end());
        
        //init
        int ans=0;
        for(int i=0;i<n;i++){
            parents[i]=-1;
        }

        //mst() using union find
        //for every it in graph
        for(auto it =graph.begin();it!=graph.end();){
            int u = it->second.first;
            int v = it->second.second;
            int w = it->first;
            // printf(" now at u:%d v:%d w:%d\n",u+1,v+1,w);
            // printf(" pu:%d pv:%d\n",find(u)+1,find(v)+1);
            if(find(u)!=find(v)){
                parents[find(v)]=find(u);
                ans+=w;
                it++;
                
            }
            // it has cycle but this e={u,v,w} has more w than before
            else{
                auto tmp = it;
                //printf(" delete u:%d v:%d w:%d\n",tmp->second.first+1,tmp->second.second+1,tmp->first);
                //delete this node
                graph.erase(tmp);
                
            }
            if(it == graph.end()){
                break;
            }
        }

        //print output (considered by vertexs-1 (mst only has v-1 edges))
        if(graph.size() == n-1){
            cout << ans << endl;
        }
        else{
            //cout << ans << "(-1)" << endl;
            cout << "-1" << endl;
        }
    }

    

}

int find(int n){
    //printf("sd");
    if (parents[n] == -1){
        return n;
    }
    n = parents[n];
    return find(n);
}