#include <iostream>
#include <list>
#include <string.h>

using namespace std;

list<long> l;

int main(void){
  int k;
  cin >> k;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  auto for_erase=l.begin();
  for(int i=1;i<k;i++){
    for_erase++;
  }
  l.erase(for_erase);
  for(auto it=l.begin();it!=l.end();it++){
    cout << *it << ' ';
  }
  return 0;
}