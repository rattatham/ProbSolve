#include <bits/stdc++.h>
using namespace std;


int board[20][20];
vector<pair<int,int>> graph[20*20];
list<int> Q;
int visited[20*20];

void find(int t);

int main(void){
    
    //init()
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            board[i][j]=0;
        }
    }
    for(int i=0;i<20*20;i++){
        visited[i]=0;
    }

    //getinput
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //printf("print[%d][%d]",i,j);
            cin >> board[i][j];
        }
        //printf("\n");
    }

    //printf("\n");
    //printboard
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",board[i][j]);
    //     }
    //     printf("\n");
    // }

    //printf("\n");
    //index = i*n+j
    //check only 
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ 
            //printf("at %d (board[%d][%d])\n",board[i][j],i,j);

            //check left can't be leftmost
            if(j!=0){
                // printf("  look left");
                // printf(" to %d\n",board[i][j-1]);
                if(board[i][j]+m >= board[i][j-1]){
                    graph[i*n+j].push_back( {i*n+j-1, board[i][j-1]});
                }
            }

            //check right can't be rightmost 
            if(j!=n-1){ 
                if(board[i][j]+m >= board[i][j+1]){
                    // printf("  look right");
                    // printf(" to %d\n",board[i][j+1]);
                    graph[i*n+j].push_back( {i*n+j+1, board[i][j+1]});
                    //graph[i*n+j+1].push_back( {i*n+j, board[i][j]});
                }
            }

            //check down can't be lowest floor
            if(i!=n-1){ //tf this node+m >= lower we can go
                if(board[i][j]+m >= board[i+1][j]){
                    // printf("  look down");
                    // printf(" to %d\n",board[i+1][j]);
                    graph[i*n+j].push_back( {(i+1)*n+j, board[i+1][j]});
                    //graph[(i+1)*n+j].push_back( {i*n+j, board[i][j]});
                    
                }
            }

            //check up can't be top floor
            if(i!=0){
                if(board[i][j]+m >= board[i-1][j]){
                    // printf("  look up");
                    // printf(" to %d\n",board[i-1][j]);
                    graph[i*n+j].push_back( {(i-1)*n+j, board[i+1][j]});
                }
            }
        }
    }

    //graph[index] = {index,weight?}
    //printgraph()
    
    // for(int i=0;i<n*n;i++){
    //     printf("%d->",i);
    //     for(auto it=graph[i].begin();it!=graph[i].end();it++){
    //         int v = it->first;
    //         int w = it->second;
    //         printf("%d->",v);
    //     }
    //     printf("\n");
    // }

    find(n*n-1);

    return 0;
}

void find(int t){
    Q.push_front(0);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        if(!visited[u]){
            visited[u]=1;
            //printf("at %d\n",u);
            for(auto it=graph[u].begin();it!=graph[u].end();it++){
                int v = it->first;
                int w = it->second;
                Q.push_back(v);
                //printf("  to %d\n",v);
                if(v == t){
                    printf("yes");
                    return;
                }
            }
        }
    }
    printf("no");
    return;
}