#include <bits/stdc++.h>
using namespace std;

list<int> years;
//58 = K

int main(void){
    int X;
    cin >> X;
    int Y=-1;
    while(Y!=0){
        cin >> Y;
        if(Y!=0){
            years.push_back(Y);
        }
    }
    years.sort();
    int checkK=1,checkC=0;
    for(auto year=years.begin();year!=years.end();year++){
        if(*year%2 == 0  && checkK){
            checkK=0;
            checkC=1;
        }
        else if(*year%2 == 0 && checkC){
            checkK=1;
            checkC=0;
        }
        else if(*year%2 == 1 && !checkK){
            checkK=1;
            checkC=0;
        }
        else if(*year%2 == 1 && !checkC){
            checkK=0;
            checkC=1;
        }
    }
    int check = X%2;
    if(check == checkK){
        cout << "C";
    }
    else{
        cout << "K";
    }
    return 0;
}