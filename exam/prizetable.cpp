#include <bits/stdc++.h>
using namespace std;
int table[250][250];
int dp[250][250][250];
int ans=-1;
int n,m,k;

int solve(int row,int col,int move);

int main(){
    for(int i=0;i<250;i++){
        for(int j=0;j<250;j++){
            for(int z=0;z<250;z++){
                dp[i][j][z] = 0;
            }
        }
    }

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int v;
            cin >> v;
            table[i][j] = v;
        }
    }

    for(int i=1;i<=m;i++){
        ans=max(solve(1,i,k),ans);
    }
    printf("%d",ans);

}

int solve(int row,int col,int move){
    //out of range?
    if(row==n+1 || col == 0 || col==m+1 || row == 0){
        return 0;
    }
    if(dp[row][col][move] != 0)
        return dp[row][col][move];
    //printf("%d\n",col);

    //move=0 run down only
    if(move==0){
        for(int i=row;i<=n;i++){
            dp[row][col][move] += table[i][col];
        }
        return dp[row][col][move];
    }
    //move(s) remain
    else{
        int move_down = solve(row+1,col,move)+table[row][col];
        int move_right = solve(row+1,col+1,move-1)+table[row][col];
        int move_left = solve(row+1,col-1,move-1)+table[row][col];
        int maxx = max(move_down,move_right);
        maxx = max(maxx,move_left);
        return dp[row][col][move]=maxx;
    }


    // for(int i=1;i<=n;i++){
    //     printf("  %d\n",dp[i][col]);
    // }

    return dp[n][col][move];
}