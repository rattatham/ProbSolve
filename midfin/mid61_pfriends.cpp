#include <bits/stdc++.h>
using namespace std;
int prime(int n);
int arr[100010];
int ans=0;

int main(){
    int count=0;
    int l,r;
    cin >> l >> r;
    if(l==1){
        l++;
    }
    for(int i=l;i<=r;i++){
        if(prime(i)){
            arr[count]=i;
            count++;
        }
    }

    // for(int i=0;i<count;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");

    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(abs(arr[i]-arr[j]) == 2){
                ans++;
            }
        }
    }
    printf("%d",ans);
}

int prime(int n){
    (double)n;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}