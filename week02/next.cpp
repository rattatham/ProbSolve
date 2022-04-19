#include <bits/stdc++.h>

using namespace std;
int check[100100];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int max_round=-1e9;
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> check[i];
    }
    /*for(int i=1;i<=N;i++){
        cout << check[i] << " ";
    }*/
    //cout << endl;
    for(int i=1;i<=N;i++){
        int round=1;
        int index=i;
        if(check[index]==i){
            continue;
        }
        while(check[index]!=i){
            //cout << index;
            index=check[index];
            round++;
        }
        if(round>max_round){
            max_round=round;
        }
    }
    cout << max_round << endl;
}