#include "probelib.h"
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int n;

void binary_search(int left,int right){
  int mid=left+(right-left)/2;
  cout << left << " " << right << endl;
  if(left==right){
    //cout << "second" << endl;
    probe_answer(left);
  }
  else if(probe_check(left,mid)){
    //cout << "third" << endl;
    binary_search(left,mid);
  }
  else{
    //cout << "fourth" << endl;
    binary_search(mid+1,right);
  }
}

main()
{
  int n = probe_init();
  binary_search(0,n);
}