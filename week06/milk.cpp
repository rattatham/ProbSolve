#include <bits/stdc++.h>
using namespace std;
int parents[100010];
int ranks[100010];

int find(int s);

int main(void){
    //init()
    for(int i=0;i<100010;i++){
        parents[i]=-1;
        ranks[i]=1;
    }

    //getinput()
    int n,q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        char cmd;
        cin >> cmd;
        int u,v;
        cin >> u >> v;

        if(cmd=='q'){ 
            //หาว่าอยู่กลุ่มเดียวกันไหม ถ้าอยู่กลุ่มเดียวกันที่ไม่ใช่ -1 ก็ตอบใช่
            if(find(u)==find(v) && (find(u)!=-1 && find(v)!= -1)){
                printf("yes\n");
            }
            //อยู่คนละกลุ่มก็ตอบไม่
            else if(find(u)!=find(v)){
                printf("no\n");
            }
        }

        //union u and v;
        else if(cmd=='c'){
            int pu = find(u);
            int pv = find(v);
            //อยู่กลุ่มเดียวกันก็ข้ามไป
            if(pu==pv){
                continue;
            }
            //เชื่อมกลุ่มน้อยเข้าหากลุ่มมาก
            if(ranks[pu]>=ranks[pv]){
                parents[pv]=pu;
                ranks[pu]+=ranks[pv];
            }
            else{
                parents[pu]=pv;
                ranks[pv]+=ranks[pu];
            }
        }


    }
    return 0;
}

int find(int s){
    if(parents[s] == -1){
        return s;
    }
    s = parents[s];
    return find(s);
}