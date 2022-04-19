#include <bits/stdc++.h>
using namespace std;

int n,d;
vector<pair<double,double>> island;


int main(void){
    n=-1;
    d=-1;
    int fail=0;
    int round=0;
    int ans=0;
    while(n!=0 && d!=0){
        round++;

        //init()
        island.clear();
        ans=-1;
        fail=0;
    
        //getinput()
        cin >> n >> d;
        for(int i=0;i<n;i++){
            double x,y;
            cin >> x >> y;
            //keep leftmost and rightmost that radar length = d can covered it 
            if((d*d-y*y) < 0){
                fail = 1;
                ans = -1;
            } 
            double left = x-sqrt(d*d-y*y);
            double right = x+sqrt(d*d-y*y);
            island.push_back({left,right});
        }

        //sort island by leftmost 
        if(!fail){
            sort(island.begin(),island.end());
        }

        //print island leftmost and rightmost corrdinates possible that radar can place
        /*for(int i=0;i<island.size();i++){
            printf("x:%lf left:%lf right:%lf \n",island[i].first,island[i].second.first,island[i].second.second);
        }*/


        //getanswer by travelling each island
        if(!fail){
            int point=0;
            //initial saved right = -inf.
            double r=-1e9;
            while(point<n){
                //check this island left if less than saved island right(r) it can be covered by one radar
                while(point<n && island[point].first <= r){
                    //if saved island right(r) more than this island right we updated r to the lesser one
                    //because it shrink area that radar can covered
                    if(r >= island[point].second){
                        r = island[point].second;
                    }
                    point++;
                }
                //if saved island right(r) is less than this island right we will use another radar
                //and updated r to new one
                ans++;
                r = island[point].second;
            }
        }
        
        //result
        if(n!=0;d!=0){
            printf("Case %d: %d\n",round,ans);
        }
    }
    return 0;
}
