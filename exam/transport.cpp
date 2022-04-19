#include <bits/stdc++.h>
using namespace std;

int tmp=0;
vector<pair<double,pair<int,int> > > edges;
pair<int,int> node[550];
int parent[550];
double ans=0;

int find(int);

int main(){
    for(int i=0;i<550;i++){
        parent[i]=-1;
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        node[i] = {x,y};
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                continue;
            }
            int xx = node[i].first-node[j].first;
            int yy = node[i].second-node[j].second;
            //printf("%d %d\n",xx,yy);
            double w = (double)(sqrt(xx*xx+yy*yy));
            //printf("%.5lf\n",w);
            //printf("%.5lf\n",xx);
            edges.push_back({w,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    for(auto edge : edges){
        double w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        //printf("%d %d %d\n",u,v,w);
        int pu = find(u);
        int pv = find(v);
        if(pv!=pu){
            parent[pu] = v;
            ans+=w;
            m--;
            if(m==2){
                break;
            }
        }
    }
    printf("%.5lf",ans);
}

int find(int n){
    if(parent[n]==-1){
        return n;
    }
    n=parent[n];
    return find(n);
}
