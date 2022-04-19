#include <iostream>
#include <list>
#include <string.h>

using namespace std;

list<long> l;

int main(void){
  int m;
  long v;
  int k;
  char cmd[5];
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> cmd;
    if(strcmp(cmd,"I")==0){
      cin >> v;
      l.push_front(v);
    }
    if(strcmp(cmd,"A")==0){
      cin >> v;
      l.push_back(v);
    }
    if(strcmp(cmd,"D")==0){
      cin >> k;
      if(k>l.size()){
        continue;
      }
      auto for_erase=l.begin();
      for(int j=1;j<k;j++){
        for_erase++;
      }
      l.erase(for_erase);
    } 
  }
  for(auto it=l.begin();it!=l.end();it++){
    cout << *it << endl;
  }
  return 0;
}