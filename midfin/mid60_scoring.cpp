#include <bits/stdc++.h>
using namespace std;

int send[110];
int score[110];

int main(){
    for(int i=0;i<110;i++){
        score[i]=-1;
        send[i]=0;
    }

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int ind,pts;
        cin >> ind >> pts;
        send[ind]++;
        //printf("  %d %d\n",score[ind],pts);
        score[ind] = max(score[ind],pts);
    }   

    int ans=0;
    for(int i=1;i<=n;i++){
        if(send[i]>5 || score[i]==-1){
            score[i]=0;
        }
        //printf("%d: %d\n",i,score[i]);
        ans+=score[i];
    }
    cout << ans;
}