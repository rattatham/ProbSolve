#include <bits/stdc++.h>

using namespace std;
vector<char> box[1010];
vector<int> graph[1010];
vector<int> s;
vector<int> t;
queue<int> Queue;
int visited[1010];

int main(void){
    int N,M;
    cin >> N >> M;
    for(int i=0;i<1010;i++){
        visited[i]=0;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char in;
            cin >> in;
            box[i].push_back(in);
        }
    }
    //cout << box[3][4];
    /*cout << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << box[i][j];
        }
        cout << endl;
    }*/
    int index=0;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<M-1;j++){
            //if 4 of it is '.' then it is a node
            if(box[i][j] == '.' && box[i][j+1] == '.' && box[i+1][j] == '.' && box[i+1][j+1] == '.'){
                if(i==0){ //start node (first line)
                    s.push_back(index);
                }
                if(i==N-2){ //finish node (last line)
                    t.push_back(index);
                }
                if(i-1>=0){
                    if(box[i][j] == '.' && box[i-1][j] == '.' && box[i][j+1] == '.' && box[i-1][j+1]){
                        graph[index].push_back(index-M+1);
                    }
                }
                if(i+2<N){
                    if(box[i+1][j] == '.' && box[i+1][j+1] == '.' && box[i+2][j] == '.' && box[i+2][j+1] == '.'){
                        graph[index].push_back(index+M-1);
                    }
                }
                if(j-1>=0){
                    if(box[i][j-1] == '.' && box[i][j] == '.' && box[i+1][j-1] =='.' && box[i+1][j] == '.'){
                        graph[index].push_back(index-1);
                    }
                }
                if(j+2<M){
                    if (box[i][j+1] == '.' && box[i][j+2] == '.' && box[i+1][j+1] == '.' && box[i+1][j+2] == '.' ){
                        graph[index].push_back(index+1);
                    }
                }
            }
            index++;
        }
    }

    while(!s.empty()){ //run bfs for every starting node in s
        int start = s.front();
        s.erase(s.begin());
        Queue.push(start);
        while(!Queue.empty()){
            int u=Queue.front();
            if(visited[u]==0){
                visited[u]=1;
                for(auto it1=graph[u].begin();it1!=graph[u].end();it1++){
                    //cout << *it1 << endl;
                    Queue.push(*it1);
                    for(auto check=t.begin();check!=t.end();check++){ //check if we found exit
                        if(*it1 == *check){
                            cout << "yes" << endl;
                            return 0;
                        }
                    }
                }
            }
            Queue.pop();
        }
    }
    cout << "no";
    return 0;
}