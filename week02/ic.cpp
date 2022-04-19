#include <iostream>
#include <list>
#include <string.h>

using namespace std;

list<long> ic;

int main(void){
  long m;
  long in;
  char x[2];
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> x;
    if(strcmp(x,"li")==0){
      cin >> in;
      ic.push_front(in);
    }
    else if(strcmp(x,"ri")==0){
      cin >> in;
      ic.push_back(in);
    }
    else if(strcmp(x,"lr")==0){
      if(ic.empty()==1){
        continue;
      }
      long tmp;
      tmp=ic.front();
      ic.pop_front();
      ic.push_back(tmp);
    }
    else if(strcmp(x,"rr")==0){
      if(ic.empty()==1){
        continue;
      }
      long tmp;
      tmp=ic.back();
      ic.pop_back();
      ic.push_front(tmp);
    }
  }
  for(auto it=ic.begin();it!=ic.end();it++){
    cout << *it << endl;
  }
  return 0;
}