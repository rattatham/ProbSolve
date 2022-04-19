#include<bits/stdc++.h>

using namespace std;
vector<int> line;
vector<int> line2;
int main(void){
    int tmp=1e9;
    int N,Q;
    int p;
    int T,t;
    scanf("%d %d",&N,&Q);
    for(int i=0;i<N;i++){
        cin >> p;
        if(p<tmp){
            tmp=p;
        }
        line.push_back(tmp);
        line2.push_back(tmp);
    }
    sort(line2.begin(),line2.end());
    for(int i=0;i<Q;i++){
        cin >> T >> t;
        if(T==1){
            cout << line[t-1] << endl;
        }
        else if(T==2){
            cout << N-(lower_bound(line2.begin(),line2.end(),t)-line2.begin()) << endl;
        }
    }
    return 0;
}
