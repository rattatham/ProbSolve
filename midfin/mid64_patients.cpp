#include <bits/stdc++.h>
using namespace std;

int days[1010];

int main(void){
    //init()
    for(int i=0;i<1010;i++){
        days[i]=0;
    }

    int n;
    //loop how many times
    cin >> n;
    for(int day=0;day<n;day++){
        int groups;
        cin >> groups;
        //for each groups will have people peoples sick for period days 
        for(int group=0;group<groups;group++){
            int period,people;
            cin >> people >> period;
            for(int j=day;j<day+period;j++){
                //printf("days[%d]+=%d\n",j,people);
                days[j]+=people;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",days[i]);
    }
    return 0;
}