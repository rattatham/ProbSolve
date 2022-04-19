#include <iostream>
#include <list>

using namespace std;

list<int> l;
//list<double> l2;
//list<type> name;

int main(){  
  int m;
  char cmd[5];//จองเผื่อๆไว้
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> cmd;
    if(cmd[0]=='I'){
      int x;
      cin >> x; //insert x
      l.push_front(x);
    }
    else{
      int k;
      cin >> k; // delete k th elements
      auto it=l.begin();
      for(int j=0;j<k-1;j++){ //เหมือน while แล้วขยับ ptr ไป k ตัว ไรงี้
        if(it!=l.end()){
          it++;
        }
      }
      if(it!=l.end()){
        l.erase(it); //ลบข้อมูลตัวที่ it ชี้อยู่
      }
    }
  }

//print
//list<int>::iterator เป็น auto ได้ เพราะ l.begin = ptr l ก็list int อยู่ละ มันก็ autoได้
for(list<int>::iterator it = l.begin(); it !=l.end(); it++){
  cout << *it <<endl; //it เป็น ptr ก็ * ก้ไดด้ค่าละ
}
//เป็นเหมือน ptr it ไปชี้ตัว begin แล้วขยับไปเรื่อยๆจน end (end = เกินลิสไป 1 ช่อง)
}