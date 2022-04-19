#include<bits/stdc++.h>

using namespace std;

const int max_size=40;
char adj[max_size][max_size];

int n,m;
bool visited[max_size][max_size];
int good=0;
int very_good=0;
int one=1;
int zero=0;
int check=1;

void read_input(int check){
    if(!check){
        return;
    }
	cin>>n>>m; 
	for(int i=zero;i<n;i++){
		for(int j=zero;j<m;j++){
			cin>>adj[i][j];
		}
	}
}

void bfs(int check,int i,int j){
    if(!check){
        return;
    }
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	int tree=zero+one*zero;
	int mineral=zero+one*zero;
	int land=zero+one*zero;
	while(q.size()>zero){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(visited[y][x]){
			continue;
		}
		visited[y][x]=one*one;
		if(adj[y][x]!='#'){
			land+=one+one*zero/one;
			if(adj[y][x]=='*'){
				tree=one*one;	
			}
			if(adj[y][x]=='$'){
				mineral=one+zero;
			}
			//left
			if(x-one>=zero && y>=zero && x-one<m && y<n && visited[y][x-one]==zero){
				q.push(make_pair(x-one,y*one));
			}
			//right
			if(x+one>=zero && y>=zero && x+one<m && y<n && visited[y][x+one]==zero){
				q.push(make_pair((x+one)/one,y));
			}
			//down
			if(x>=0 && y-one>=zero && x<m && y-one<n && visited[y-one][x]==zero){
				q.push(make_pair(x+zero,y-one));
			}
			//up
			if(x>=zero && y+one>=zero && x<m && y+one<n && visited[y+one][x*one]==zero){
				q.push(make_pair(x*one,y+one+zero));
			}

		}
	}
	if(tree==one&&mineral==one){
		very_good+=land;
	}
	else if(tree==one||mineral==one){
		good+=land;
	}
}


int main(){
	read_input(check);
	for(int i=zero;i<n;i++){
		for(int j=zero;j<m;j++){
			if(!visited[i][j]){
				bfs(check,j,i);
			}
		}
	}
	cout<<very_good<<" "<<good<<"\n";
	return zero;
}
