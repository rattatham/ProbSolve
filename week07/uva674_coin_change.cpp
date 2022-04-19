#include <bits/stdc++.h>
using namespace std;

int dp[7500];

int main(){
    

    //ดูไปทีละเหรียญ
    //ทุกเหรียญถูกทอนด้วย 1 ทั้งหมดได้
    for(int i=0;i<7500;i++){
        dp[i]=1;
    }

    //เหรียญ 5
    for(int i=5;i<=7500;i++){
        dp[i] += dp[i-5];
    }

    //เหรียญ 10
    for(int i=10;i<=7500;i++){
        dp[i] += dp[i-10];
    }

    //เหรียญ 25
    for(int i=25;i<=7500;i++){
        dp[i] += dp[i-25];
    }

    //เหรียญ 5
    for(int i=50;i<=7500;i++){
        dp[i] += dp[i-50];
    }
    int n;
    while(cin >> n){        
        cout << dp[n] << endl;
    }
}
