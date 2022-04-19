#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> schedule;

int main(void){
    int n;
    cin >> n;
    int deadline,duration;
    for(int i=0;i<n;i++){
        cin >> deadline >> duration; 
        schedule.push_back({deadline,duration});
    }
    //sort by deadline of works[i]
    sort(schedule.begin(),schedule.end());
    
    //cout << endl;
    // printf("d  :t\n");
    // for (auto works : schedule){
    //     printf("%d :%d\n",works.first+10,works.second);
    // }
    
    int price=0;
    int D=0;
    for(auto it = schedule.begin(); it != schedule.end(); it++){
        D+=it->second;
        int tmp_rate = (D - it->first - 10);
        int rate = max(0,tmp_rate); //in case of tmp_rate < 0
        // printf("P = %d - %d - 10\n",D,it->first);
        // printf("rate = %d\n",rate*1000);
        price = max(price,rate*1000);
    }
    cout << price;
    return 0;
}