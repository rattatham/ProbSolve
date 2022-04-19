#include <bits/stdc++.h>
using namespace std;


int main(){
    float n,x,y,r;
    int ans=0;
    cin >> n >> x >> y >> r;
    for(int i=0;i<n;i++){
        float xn,yn;
        cin >> xn >> yn;
        // printf("%f <= %f\n",pow(xn-x,2)+pow(yn-y,2),pow(r,2));
        if( (pow(xn-x,2)+pow(yn-y,2) <= pow(r,2))){
            ans++;
        }
    }
    cout << ans;
}