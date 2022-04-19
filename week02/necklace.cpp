#include<bits/stdc++.h>
using namespace std;
//vector<int> necklace[300100];
int front[300100];
int back[300100];
int now[300100];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        front[i]=-1;
        back[i]=-1;
        now[i]=i;
    }
    for(int i=1;i<N;i++){
        int add,to;
        cin >> add >> to;
        /*if(back[to]==-1){
            back[to]=add;
            front[add]=to;
        }
        else{*/
        //int now=back[add];
        int tmp=back[to];
        back[to]=add;
        front[add]=to;
        //cout << now << endl;
        while(back[add]!=-1){
            //cout << "HI";
            add=back[add];
        }
        back[add]=tmp;
        //}
    }
    int res;
    for(int i=1;i<=N;i++){
        if(front[i]==-1){
            res=i;
        }
    }
    while(back[res]!=-1){
        cout << now[res] << " ";
        res=back[res];
    }
    cout << res;
    return 0;
}