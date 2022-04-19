#include <iostream>
#define size 1000010

int tree[size];

using namespace std;

int searchchild(int p,int c){ //p=4 c=1
    int index=p*1000;
    if(p==c){
        return 1;
    }
    for(int i=index;tree[i]!=0;i++){
        if(searchchild(tree[i],c)){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int N,M;
    int p;
    cin >> N >> M;
    for(int i=2;i<N+1;i++){
        cin >> p;
        int index=p*1000;
        while(tree[index]!=0){ 
            index++;
        }
        tree[index]=i;
    }
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        if(a==b){ //both same
            cout << a << endl;
            continue;
        }
        else if(a==0 || b==0){ //zero
            cout << -1 << endl;
            continue;
        }
        else if(searchchild(a,b)){
            cout << a << endl;
        }
        else if(searchchild(b,a)){
            cout << b << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}