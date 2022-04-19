#include <bits/stdc++.h>
using namespace std;


//min move str[i][left][right]
int dp[1010][26][26];
int solve(char arr[],int len,int left,int right,int now);
int distance(int now,int go);

int main(){
    int n;
    cin >> n;
    while(n--){
        //init
        for(int i=0;i<1010;i++){
            for(int j=0;j<=26;j++){
                for(int k=0;k<=27;k++){
                    dp[i][j][k]=1e9;
                }
            }
        }

        char a[1010];
        cin >> a;
        int len_a = strlen(a);
        // for(int i=0;i<len_a;i++){
        //     printf("%c %d\n",a[i],a[i]-65);
        // }

        //boundary
        int first_char = (int)a[0]-'A'+1;
        dp[0][first_char][1] = distance(1,first_char);
        dp[0][1][first_char] = distance(1,first_char);

        //solve
        for(int i=1;i<len_a;i++){
            int word = (int)a[i]-'A'+1;
            //printf("  word:%d\n",word);
            for(int j=1;j<=26;j++){
                for(int k=1;k<=26;k++){
                    if(dp[i-1][j][k]!=1e9){
                        //printf("last at dp[%d][%d][%d] = %d",i,word,k,dp[i][word][k]);
                        dp[i][word][k] = min(dp[i][word][k], dp[i-1][j][k]+distance(j,word));
                        dp[i][j][word] = min(dp[i][j][word], dp[i-1][j][k]+distance(k,word));
                    }
                }
            }
        }

        //printf("\n");
        int final_word = (int)a[len_a-1]-'A'+1;
        //printf("  final_word:%d\n",final_word);
        int min1 = 1e9;
        for(int i=1;i<=26;i++){
            //printf("%d\n",dp[len_a-1][final_word][i]);
            min1 = min(min1,dp[len_a-1][final_word][i]);
        }
        //printf("\n");
        int min2=1e9;
        for(int i=1;i<=26;i++){
            //printf("%d\n",dp[len_a-1][i][final_word]);
            min2 = min(min2,dp[len_a-1][i][final_word]);
        }

        cout << min(min1,min2) << endl;
    }
}

int distance(int now,int go){
    int dis1 = abs(go-now);
    int dis2 = now+(26-go);
    int dis3 = (26-now)+go;
    return min({dis1,dis2,dis3});
}



