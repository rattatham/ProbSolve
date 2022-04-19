#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1010];
int color[1010];
int ans_u;
int ans_v;
list<int> Q;
int color_now=0;

void colored(int s);

int main(void){
    //init()
    //-1 = no color 0 = red, 1 = blue
    for(int i=0;i<1010;i++){
        color[i]=-1;
    }


    //getinput()
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //colored all the graph;
    //loop every node in case it is not connected graph
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            colored(i);
        }
    }


    //printgraph() and color
    /*for(int i=0;i<n;i++){
        printf("%d(%d)->",i+1,color[i]);
        for(auto it=graph[i].begin();it!=graph[i].end();it++ ){
            printf("%d->",*it+1,color[*it]);
        }
        cout << endl;
    }*/
    

    //for all nodes
    int check=0;
    for(int i=0;i<n;i++){
        int color_now = color[i];
        int count_red=0;
        int count_blue=0;
        int tmp_red=-1;
        int tmp_blue=-1;
        //ไล่ดูทุกตัวที่ติดกับ node นี้
        for(auto it=graph[i].begin();it!=graph[i].end();it++ ){
            if(color[*it]==0){
                //save ค่าของสีแดงที่เจอเป็นตัวแรก
                if(count_red==0){
                    tmp_red = *it;
                }
                count_red++;
            }
            else if (color[*it] == 1){
                 //save ค่าของน้ำเงินที่เจอเป็นตััวแรก
                if(count_blue==0){
                    tmp_blue = *it;
                }
                count_blue++;
            }

            //ไม่มีสีเดียวกันติดกับ node ปัจจุบัน ก็ข้าม
            //ตอนนี้สีแดง ไม่มีสีแดงติดอยู่เลย
            if(color_now == 0 && count_red == 0){
                continue;
            }
            //ตอนนี้สีน้ำเงิน ไม่มีสีน้ำเงินติดอยู่เลย
            if(color_now == 1 && count_blue == 0){
                continue;
            }

            //กรณีที่มีมากกว่าอย่างละตัว มันจะมีหนึ่งสีที่มีตัวเดียว
            // first priority เสมอ ถ้ามีแล้วจบทันที ???????????????????
            //กรณีมีน้ำเงินตัวเดียว (สีแดงที่ติดอยู่มีหลายตัว)
            if(count_blue == 1 && count_red>1){
                check=1;
                ans_u = i;
                ans_v = tmp_blue;
                break;
            }
            //กรณีที่มีสีแดงตัวเดียว (สีน้ำเงินที่ติดอยู่มีหลายตัว)
            if(count_red == 1 && count_blue>1){
                check=1;
                ans_u = i;
                ans_v = tmp_red;
                break;
            }

            //ตัวติดกันมีทัั้งสองสี แต่มีอย่างละ 1 ตัว
            if(count_blue == 1 && count_red == 1){
                //ถ้าตัวนี้เป็นสีแดง ต้องตัดตัวที่ติดกันที่เป็นสีแดง
                if(color_now == 0){
                    ans_u = i;
                    ans_v = tmp_red;
                }
                //เป็นสีน้ำเงิน ก็ต้องตัดตัวที่ติดกันที่เป็นสีน้ำเงิน
                else{
                    ans_u = i;
                    ans_v = tmp_blue;
                }
                    
            }
        }
        if(check){
            break;
        }
        
    }
    if(ans_u < ans_v)
        printf("%d %d\n",ans_u+1,ans_v+1);
    else
        printf("%d %d\n",ans_v+1,ans_u+1);
    return 0;
}

void colored(int s){
    Q.push_back(s);
    color[s] = color_now;
    while(!Q.empty()){
        //only color 0 and 1
        int u = Q.front();
        color_now = (color[u]+1)%2;
        //printf("now at %d(%d)\n",u+1,color[u]);
        //printf("gonna colored to %d\n",color_now);
        Q.pop_front();
        for(auto it=graph[u].begin();it!=graph[u].end();it++){
            // has no color yet
            if(color[*it]==-1){
                color[*it] = color_now;
                Q.push_back(*it);
               // printf("  %d as %d\n",*it+1,color[*it]);
            }
            //if node *it has color
            //check if u and *it has the same color;
            /*else if(color[u] == color[*it]){
                printf("found %d %d\n",u+1,*it+1);
                ans_u = u;
                ans_v = *it;
            }*/
        }
    }
}