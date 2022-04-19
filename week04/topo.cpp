#include <bits/stdc++.h>

using namespace std;
int in_degree[100010];
vector<int> graph[100010];
list<int> q;
int N=-1,M=-1;
int visited[100010];
list<int> answer;

void bfs();


int main(void){
    cin >> N >> M;
    if(N == 0 && M == 0){
        return 0;
    }

    //init()
    for(int i=0;i<N;i++){
        graph[i].clear();
        q.clear();
        answer.clear();
        in_degree[i]=0;
        visited[i]=0;
    }

    //get_input()
    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    //find starting all node
    for(int i=0;i<N;i++){
        if(in_degree[i]==0){
            q.push_back(i);
        }
    }
    bfs();
    if(answer.size()!=N){
        cout << "no";
        return 0;
    }
    auto it=answer.begin();
    cout << *it;
    it++;
    for(it;it!=answer.end();it++){
        cout << " " << *it ;
    }
    cout << endl;
}

//จะอยู่ใน q ได้ แปลว่า in_degree =0 เพราะฉะนั้น ตอน pop ก็ print น่าจะได้เลยนะ ทำไมออกซ้ำวะ
void bfs(){
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        answer.push_back(u+1);
        for(auto it=graph[u].begin();it!=graph[u].end();it++){
            int v=*it;
            in_degree[v]-=1;
            if(in_degree[v]==0){
                visited[v]=1;
                q.push_back(v);
            }
        }
    }
}

