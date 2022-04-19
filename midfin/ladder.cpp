#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[2010];

int main(){
    //init()
    for(int i=0;i<2010;i++){
        board[i]=0;
    }

    //get board and dice 
    cin >> n >> m;

    //fill board
    for(int i=1;i<=n;i++){
        cin >> board[i];
    }
    board[n]=0;

    int now = 0;
    //printf("start %d\n",now);

    //printf("---%d---\n",n);
    //walk
    for(int i=0;i<m;i++){
        int dice;
        cin >> dice;
        //printf("dice = %d\n",dice);
        now+=dice;
        if(board[now]!=0){
            now+=board[now];
        }
        if(now>n){
            now = n;
        }
        if(now<0){
            now = 0;
        }
        //printf("  go to %d found %d",now,board[now]);

        //printf("  now at %d\n",now);
    }


    cout << now << endl;
}