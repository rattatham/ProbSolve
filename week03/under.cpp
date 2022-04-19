#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> highway;
int km[350];
int main(void){
    int max=-1e9;
    int N,L;
    cin >> N >> L;
    for(int i=0;i<L;i++){
        int s,e;
        cin >> s >> e;
        highway.push_back(make_pair(s,e));
    }
    for(int i=0;i<L;i++){
        for(int j=highway[i].first;j<highway[i].second;j++){
            km[j]+=1;
        }
    }
    for(int i=0;i<N;i++){
        if(km[i]>max){
            max=km[i];
        }
    }
    cout << max;
    return 0;
}