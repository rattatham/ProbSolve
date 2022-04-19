#include <stdio.h>

int main(void){
  int n,k,t;
  scanf("%d %d %d",&n,&k,&t);
  int now=1;
  int round=1;
  while(now!=t){
    now=(now+k)%n;
    if(now==1){
      break;
    }
    round+=1;
  }
  printf("%d",round);
  return 0;
}