#include <bits/stdc++.h>

using namespace std;

vector<long long> p;
long long ans=0;

int main(void){
    long long n,a,b;
    cin >> n >> a >> b;
    for(long long i=0;i<n;i++){
        long long v;
        cin >> v;
        p.push_back(v);
    }
    sort(p.begin(),p.end());

    for(long long i=0;i<n;i++){
        long long low = a-p[i];
        long long high = b-p[i];
        if(low<0){
            low = 0;
        }
        //not considered past price
        long long lowerbound = lower_bound(p.begin()+i+1,p.end(),low) - p.begin();
        long long upperbound = upper_bound(p.begin()+i+1,p.end(),high) - p.begin();
        if(lowerbound > upperbound){
            continue;
        }
        else{
            ans+= upperbound-lowerbound;
        }
    }
    cout << ans;
}