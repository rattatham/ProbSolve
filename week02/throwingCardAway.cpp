#include <iostream>
#include<list>

using namespace std;

list<int> hold;

int main(void){
  int card;
  int tmp;
  int dis;
  while(1){
    hold.clear();
    cin >> card;
    if(card==0){
      break;
    }
    for(int j=1;j<=card;j++){
      hold.push_back(j);
    }
    cout << "Discarded cards: ";
    while(hold.size()!=1){
      dis=hold.front();
      hold.pop_front();
      tmp=hold.front();
      hold.pop_front();
      hold.push_back(tmp);
      cout << dis;
      if(hold.size()>1){
        cout << ", ";
      }
    }
    cout << endl;
    cout << "Remaining card: " << hold.front() << endl;
  }
  return 0;
}