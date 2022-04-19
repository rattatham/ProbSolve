#include <bits/stdc++.h>

using namespace std;


int main(void){
    int K;
    cin >> K;
    for(int round=0;round<K;round++){
        //cout << round;
        //read_input()
        int N,M;
        cin >> N >> M;

        //init()
        int color[N];
        for(int i=0;i<N;i++){
            color[i]=-1;
        }
        int check=1;
        for(int i=0;i<M;i++){
            int u,v;
            cin >> u >> v;
            u--;v--;
            //if they don't have color yet.
            if(color[u]==-1 && color[v]==-1){
                color[u]=0;
                color[v]=1;
            }
            //if a node has color
            else if(color[u]==-1){
                color[u]=(color[v]+1)%2;
            }
            else if(color[v]==-1){
                color[v]=(color[u]+1)%2;
            }
            //if they have same color
            if(color[u]==color[v]){
                check=0;
            }
        }
        if(check){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }

    }
    return 0;
}
