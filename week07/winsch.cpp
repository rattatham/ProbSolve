#include <bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>> jobs;


void solve(int n);
//P[i] will keep the index of the last compatible jobs with jobs[i]
int P[1010];

int main(){
    for(int i=0;i<1010;i++){
        P[i]=-1;
    }

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int s,t,w;
        cin >> s >> t >> w;
        jobs.push_back({w,{s,t}});
    }
    //jobs are sorted

    //finding P[i]
    for(int i=n-1;i>=0;i--){
        int starti = jobs[i].second.first;
        int finishi = jobs[i].second.second;
        int weighti = jobs[i].first;
        //printf("s:%d t:%d w:%d\n",starti,finishi,weighti);
        //loop back for every jobs
        for(int j=i-1;j>=0;j--){
            int finishj = jobs[j].second.second;
            // if jobs j finish before jobs i start
            if(finishj<=starti){
                //i and j are compatible
                P[i]=j;
                break;
            }
        }
    }


    //check P[i]
    // for(int i=0;i<n;i++){
    //     if(P[i]!=-1){
    //         printf("works %d compatible with works %d\n",i+1,P[i]+1);
    //         int starti = jobs[i].second.first;
    //         int finishi = jobs[i].second.second;
    //         int weighti = jobs[i].first;
    //         int j = P[i];
    //         int startj = jobs[j].second.first;
    //         int finishj = jobs[j].second.second;
    //         int weightj = jobs[j].first;
    //         printf("  %d: %d %d %d\n",i,starti,finishi,weighti);
    //         printf("  %d: %d %d %d\n",j,startj,finishj,weightj);
    //     }
    //     else{
    //         printf("no works compatable with %d\n",i+1);
    //     }
    // }
    solve(n);

}

void solve(int n){
    //store index of jobs list in answer
    list<int> arr;

    //dp will store best value from 0 to i
    int dp[1010];
    for(int i=0;i<1010;i++){
        dp[i]=-1;
    }

    //boundary
    dp[0] = jobs[0].first;
    
    for(int i=1;i<n;i++){
        int now_w = jobs[i].first;
        //if this jobs has jobs that compatable with
        if(P[i]!=-1){
            now_w += dp[P[i]];
        }
        //dp[i] = max(now_w,dp[i-1]);
        
        //find max and save the jobs list
        if(now_w > dp[i-1]){
            dp[i] = now_w;
            arr.push_back(i);
        }
        else{
            dp[i] = dp[i-1];
        }
    }

    int ans = dp[n-1];
    cout << ans << endl;

    for(int i=0;i<n;i++){
        printf("dp[%d] = %d\n",i,dp[i]);
    }
}