#include <stdio.h>

int main(void){
  int n,x;
  int res=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&x);
    if(x>0){
      res+=x;
    }
  }
  printf("%d",res);
  return 0;
}