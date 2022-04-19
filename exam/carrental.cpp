#include<bits/stdc++.h>
using namespace std;

int C[110],P[110],W[110];
int items[1010];

int main(void){
    int K,N;
    int min=1e9;
    cin >> K >> N;
    for(int i=0;i<K;i++){
        cin >> C[i] >> P[i] >> W[i];;
    }
    for(int i=0;i<N;i++){
        int item;
        cin >> items[i];
    }
    for(int i=0;i<K;i++){
        int price;
        int chk=1;
        for(int j=0;j<N;j++){  //chk if items[i] exceed W[j]
            if(items[j]>W[i]){
                chk=0;
            }
        }
        int weight=0;
        int round=1;
        for(int j=0;j<N;j++){
            //cout << round << endl;
            //cout << weight << endl;
            if(weight+items[j]>W[i]){
               round+=1;
               weight=items[j]; 
               continue;
            }
            weight+=items[j];
        }
        price=C[i]+P[i]*round;
        //cout << price << " " << round << endl;
        if(chk==1){
            if(price<min){
                min=price;
            }
        }
    }
    cout << min << endl;
}