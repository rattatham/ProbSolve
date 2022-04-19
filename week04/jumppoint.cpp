#include<bits/stdc++.h> //2loopok
using namespace std;
const int MAX_point=1010;
vector<pair<int,int>> coordinates;
vector<int> point[MAX_point+2];
list<int> q;
bool visited[MAX_point+2];
int dist[MAX_point+2];
int pred[MAX_point];

void bfs(int src,int dest){
    visited[src]=true;
    dist[src]=0;
    q.push_back(src);
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for(auto it=point[u].begin();it!=point[u].end();it++){
            int node=*it;
            if(visited[node]==false){
                visited[node]=true;
                dist[node]=dist[u]+1;
                q.push_back(node);
                if(node==dest){
                    return;
                }
            }
        }
    }
}

int main(void){
    int n,r;
    cin >> n >> r;
    for(int i=0;i<n+2;i++){
        visited[i]=false;
        dist[i]=-1;
        pred[i]=-1;
    }
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        coordinates.push_back(make_pair(x,y));
    }
    /*for(int i=0;i<n;i++){
        cout << coordinates[i].first << " " << coordinates[i].second << endl;
    }*/
    for(int i=0;i<n;i++){
        //check if can jump from origin
        if(pow(100,2)+pow(100,2)<=pow(r,2)){
            cout << 1;
            return 0;
        }
        //check with origin
        if(pow(coordinates[i].first,2)+pow(coordinates[i].second,2)<=pow(r,2)){ 
            point[0].push_back(i+1);
            point[i+1].push_back(0);
        }
        //check with 100,100
        if(pow(100-coordinates[i].first,2)+pow(100-coordinates[i].second,2)<=pow(r,2)){ 
            point[n+1].push_back(i+1);
            point[i+1].push_back(n+1);
        }
        //check with another point
        for(int j=i+1;j<n;j++){
            //cout << coordinates[i].first << " " << coordinates[i].second << endl;
            //cout << coordinates[j].first << " " << coordinates[j].second << endl;
            if(pow(coordinates[j].first-coordinates[i].first,2)+pow(coordinates[j].second-coordinates[i].second,2)<=pow(r,2)){
                point[j+1].push_back(i+1);
                point[i+1].push_back(j+1);
            }
        }
    }
    bfs(0,n+1);
    cout << dist[n+1];

    /*for(int i=0;i<n+2;i++){
        cout << i << " ";
        for(auto it=point[i].begin();it!=point[i].end();it++){
            cout << *it << " ";
        }
        cout << endl;
    }*/
}