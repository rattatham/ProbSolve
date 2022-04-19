#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int num=-1;

void rails(){
  int x;
  while(1){
    int count=1;
    while(s.size()>0){
      s.pop();
    }
    for(int i=0;i<num;i++){
      cin >> x;
      if(x==0){
        return;
      }
      while(count<=num+1){
        if(count==x){
          count++;
          break;
        }
        if(s.size()>0 && s.top()==x){
          s.pop();
          break;
        }
        s.push(count);
        count++;
      }
    }
    if(s.size()==0){
      printf("Yes\n");
    }
    else{
      printf("No\n");
    }
  }
}

int main(void){
  while(1){
    cin >> num;
    if(num==0){
      break;
    }
    rails();
    cout << endl;
  }
  return 0;
}