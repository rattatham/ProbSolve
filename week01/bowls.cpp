#include <stdio.h>
int main(void){
  int bowl[100010]={};
  int n,x;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&x);
    bowl[x]+=1;
  }
  int max=-99999;
  for(int i=0;i<100010;i++){
    if(bowl[i]>max){
      max=bowl[i];
    }
  }
  printf("%d",max);
  return 0;
}