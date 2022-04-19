#include <bits/stdc++.h>
using namespace std;

#define max_int 1e9
vector<int> redgraph[50010];
vector<int> blackgraph[50010];
int red_dis[50010];
int black_dis[50010];
/*int red_visited[50010];
int black_visited[50010];
int red_ans=-1;
int black_ans=-1;*/
list<int> Qr;
list<int> Qb;

int main(void){
    //init()
    for(int i=0;i<50010;i++){
        red_dis[i]=max_int;
        black_dis[i]=max_int;
        //red_visited[i]=0;
        //black_visited[i]=0;
    }

    //getinput()
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int u,v,color;
        cin >> u >> v >> color;
        u--;v--;
        //if no color we connect it in both graph
        if(color==0){
            redgraph[u].push_back(v);
            redgraph[v].push_back(u);
            blackgraph[u].push_back(v);
            blackgraph[v].push_back(u);
        }
        //color 1 = red
        else if(color==1){
            redgraph[u].push_back(v);
            redgraph[v].push_back(u);
        }
        //color 2 = black
        else if(color==2){
            blackgraph[u].push_back(v);
            blackgraph[v].push_back(u);
        }
    }

    //shortestpath both red and black road as if we walk only one color
    //all weight = 1

    //shortestpath red graph first start at s;
    Qr.push_back(s);
    red_dis[s] = 0;
    while(!Qr.empty()){
        int u = Qr.front();
        Qr.pop_front() ;
        for(auto it=redgraph[u].begin();it!=redgraph[u].end();it++){
            if(red_dis[*it] > red_dis[u]+1){
                red_dis[*it] = red_dis[u]+1;
                Qr.push_back(*it);
            }
        }
    }

    //shortestpath black graph start at s;
    Qb.push_back(s);
    black_dis[s] = 0;
    while(!Qb.empty()){
        int u = Qb.front();
        Qb.pop_front();
        for(auto it=blackgraph[u].begin();it!=blackgraph[u].end();it++){
            if(black_dis[*it]> black_dis[u]+1){
                black_dis[*it] = red_dis[u]+1;
                Qb.push_back(*it);
            }
        }
    }

    if(red_dis[t] == max_int && black_dis[t] == max_int){
        printf("%d\n",-1);
    }

    //if(red_dis[t] < black_dis[t]){
        cout << "red" << endl;
        cout << red_dis[t] << endl;
    //}
    //else{
        cout << "black" << endl;
        cout << black_dis[t] << endl; 
    //}


    return 0;
}