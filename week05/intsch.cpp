#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> work; 

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second<b.second);
}

vector<pair<int,int>> ans;

int main(void){
    //getinput()
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int s,t;
        cin >> s >> t;
        work.push_back({s,t});
    }
    sort(work.begin(),work.end(),sortbysec);
    
    //printschedule()
    /*for(int i=0;i<n;i++){
        printf("s:%d , t:%d\n",work[i].first,work[i].second);
    }
    cout << endl;*/

    //greedy() 
    int least_end_time;
    for(int i=0;i<n;i++){
        //init()
        if(i==0){
            ans.push_back({work[i].first,work[i].second});
            least_end_time = work[i].second;
        }
        else if(work[i].first>=least_end_time){
            ans.push_back({work[i].first,work[i].second});
            least_end_time = work[i].second;
        }
    }
    int len_ans = ans.size();
    cout << ans.size() << endl;
    /*for(int i=0;i<len_ans;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }*/

    return 0;
}