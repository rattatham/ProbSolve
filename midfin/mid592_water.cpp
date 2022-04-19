#include <bits/stdc++.h>
using namespace std;



int main(void){
    int waterlevel[1010];
    int days;
    int ans=0;
    cin >> days;
    for(int i=0;i<days;i++){
        cin >>waterlevel[i];
        if(i==0){
            //cout << "first day\n";
            continue;
        }
        int waterdiff = waterlevel[i-1]-waterlevel[i];
        //cout << "waterdiff: " << waterdiff ;
        if(waterdiff>10){
            if(waterdiff*10>=700){
                //cout << " exceed";
                ans+=700;
            }
            else{
                //cout << " OK";
                ans+=waterdiff*10;
            }
        }
        cout << endl;
    }
    cout << ans;

    return 0;
}