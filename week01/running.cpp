#include <stdio.h>
int main(void){
  double race[100010]={};
  int n,s;
  scanf("%d %d",&n,&s);
  double x;
  for(int i=0;i<n;i++){
    scanf("%d",&x);
    race[i]=x;
  }
  double max=9999;
  int fastest=0;
  for(int i=0;i<n;i++){
    if(race[i]<max){
      max=race[i];
      fastest=i;
    }
  }
  int people=n;
  for(int i=0;i<n;i++){
    if(i!=fastest){
      if((double)race[i]*(s-1)>=(double)max*(s)){
        people-=1;
      }
    }
  }
  printf("%d\n",people);
  return 0;
}