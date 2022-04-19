#include <bits/stdc++.h>

using namespace std;


int main(void){
    int round[200010];
    int N,food;
    int index;
    int max=-1e9;
    cin >> N;
    for(int i=1;i<N+1; i++){
        round[i]=0;
    }
    for(int i=1;i<N+1;i++){
        cin >> food;
        if(food>i){           //check ว่าถ้าใส่ food ที่ index i ต้องหมุนไปกี่รอบถึงจะตรง
            index=food-i;     //เช่นใส่ food=3 ที่ index=1 ก็ต้อง หมุน 3-1 = 2 รอบถึงจะตรง
            round[index]++;
        }
        else{
            index=food+N-i; 
            round[index]++;
        }
    }
    
    for(int i=1;i<N+1;i++){
        if(round[i]>max){
            max=round[i];
        }
    }
    cout << max;
    return 0;
}