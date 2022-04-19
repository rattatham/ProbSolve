#include <bits/stdc++.h>
using namespace std;
int a[1010];
int b[1010];
int c[1010];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n-1;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int level = 1;
    int achk = 0;
    int bchk=0;
    int cchk=0;
    for(int i=0;i<m;i++){
        int dis,box,show;
        cin >> dis >> box >> show;
        //printf("now level = %d\n",level);

        if(dis>=a[level]){
            achk=1;
        }
        if(box>=b[level]){
            bchk=1;
        }
        if(show>=c[level]){
            cchk=1;
        }

        //pass this track
        if(achk == 1 && bchk == 1 && cchk == 1){
            achk=0;
            bchk=0;
            cchk=0;
            level++;
        }
    }
    if(level > n){
        level = n;
    }
    cout << level;
}