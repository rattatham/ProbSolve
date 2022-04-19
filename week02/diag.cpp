#include <bits/stdc++.h>
using namespace std;

vector<long long> sx;
vector<long long> sy;
long long ans=0;

int main(void){
    long long n;
    cin >> n;
    for(long long i=0;i<n;i++){
        long long x,y;
        cin >> x >> y;
        //หมุนแกน จะได้แกน x = x+y และแกน y = y-x
        sx.push_back(x+y);
        sy.push_back(y-x);
    }
    sort(sx.begin(),sx.end());
    sort(sy.begin(),sy.end());
    
    //if even = no middle
    long long medx,medy;
    if(n%2==0){
        medx = (sx[n/2]+sx[(n/2)-1])/2;
        medy = (sy[n/2]+sy[(n/2)-1])/2;
    }
    else{
        medx = sx[n/2];
        medy = sy[n/2]; 
    }

    for(long long i=0;i<n;i++){
        ans+=abs(medx-sx[i]);
        ans+=abs(medy-sy[i]);
    }
    cout << ans;
}