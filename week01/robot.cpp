#include <stdio.h>

int main(void){
  char walk[110];
  int x=0,y=0;
  scanf("%s",walk);
  for(int i=0;i<100;i++){
    if(walk[i]=='N'){
      y+=1;
    }
    else if(walk[i]=='W'){
      x-=1;

    }
    else if(walk[i]=='E'){
      x+=1;

    }
    else if(walk[i]=='S'){
      y-=1;
    }
    else if(walk[i]=='Z'){
      x=0;y=0;
    }
  }
  printf("%d %d\n",x,y);
  return 0;
}