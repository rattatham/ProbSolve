#include <stdio.h>

int main(void){
  int a[4];
  for(int i=0;i<4;i++){
    scanf("%d",&a[i]);
  }
  int ans=0;
  ans=a[0]+a[1]+a[2]+a[3];
  printf("%d",ans);
  return 0;
}