#include <iostream>
#include <list>

using namespace std;

list<int> hold;
list<int> card;

int main(void){
  int n,dis,tmp;
  while(1){
    cin >> n;
    card.push_back(n);
    if(n==0){
      break;
    }
  }
  for(auto it=card.begin();it!=card.end();it++){
    hold.clear();
    if(*it==0){
      break;
    }
    for(int i=1;i<=*it;i++){
      hold.push_back(i);
    }
    cout << "Discarded cards:";
    while(hold.size()!=1){
      dis=hold.front();
      hold.pop_front();
      tmp=hold.front();
      hold.pop_front();
      hold.push_back(tmp);
      cout << " " << dis;
      if(hold.size()>1){
        cout << ",";
      }
    }
    cout << endl;
    cout << "Remaining card: " << hold.front() << endl;
  }
  return 0;
}