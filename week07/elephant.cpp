#include <bits/stdc++.h>
using namespace std;
int banana[100010];
//store most value from 0 to i
int dp[100010];
void solve(int);

int main(){
    for(int i=0;i<100010;i++){
        banana[i]=-1;
        dp[i]=-1;
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> banana[i];
    }
    solve(n);
}

void solve(int n){
    //boundary
    dp[-1]=0;
    dp[0]=0;
    dp[1]=0;
    //printf("dp[%d]:%d\n",2-3,dp[2-3]);
    //top down
    for(int i=2;i<n;i++){
        //printf("%d+%d , %d\n",banana[i],dp[i-3],dp[i-1]);
        dp[i] = max(banana[i]+dp[i-3],dp[i-1]);
    }
    cout << dp[n-1];
}