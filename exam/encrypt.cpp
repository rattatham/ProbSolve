#include <bits/stdc++.h>
using namespace std;

list<int> num;

int main(){
    int n,s;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        num.push_back(x);
    }
    int tmp=1;
    if(n<20){
        for(int i=n;i<20;i++){
           num.push_back(tmp);
            tmp++;
        }
    }
    
    list<int> ans = num;
    // for(auto number : num){
    //     printf("%d ",number);
    // }
    
    int tmp_splice = 20-s;
    auto splice_it = num.begin();
    for(int i=0;i<tmp_splice;i++){
        splice_it++;
    }
    //printf("%d",tmp_splice);
    ans.splice(ans.begin(),num,splice_it,num.end());
    vector<int> res;
    for(auto number : ans){
        //printf("%d ",number);
        res.push_back(number);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            printf("%d ",res.at(i+j*5));
        }
    }
}