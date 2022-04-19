#include<bits/stdc++.h>
using namespace std;
vector<double> price;


int main(void){
    double n,q,list;
    double buy,coupon;
    double sum;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> list;
        price.push_back(list);
    }
    for(int i=0;i<q;i++){
        cin >> buy >> coupon;
        vector<double>::iterator it=price.begin()+(buy-1);
        sum=*it+coupon;
        cout << upper_bound(price.begin(),price.end(),sum)-price.begin() << endl;
    }
    return 0;
}