#include<bits/stdc++.h>
using namespace std;

//2d array store taro and tora least power used from start to i
//second dimension is for k
int dp[100010][300];
int taro[100010];
int tora[100010];
void solve(int,int);

int main(){
    int c;
    cin >> c;
    while(c--){
        int ans = 1e9;
        for(int i=0;i<100010;i++){
            for(int j=0;j<300;j++){
                dp[i][j]=1e9;
            }
        }
        int n,k;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> taro[i] >> tora[i];
        }
        int s = 101-k;
        int t = 101+k;
        dp[0][101] = 0;
        int tmp=-1;
        for(int i=1;i<n+1;i++){
            tmp++;
            for(int j=s;j<=t;j++){
                //printf("%d",tmp);
                //printf("  %d %d\n",taro[tmp],tora[tmp]);
                dp[i][j] = min(dp[i-1][j-1]+taro[tmp],dp[i-1][j+1]+tora[tmp]);
                //printf("---exe---\n");
            }
        }

        // for(int i=1;i<n+1;i++){
        //     for(int j=s;j<=t;j++){
        //        printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
        //     }
        // }

        for(int i=s;i<=t;i++){
            //printf("dp[%d][%d] = \n",n,i);
            ans = min(dp[n][i],ans);
        }
        cout << ans << endl;
    }

}