#include <stdio.h>
#include <math.h>

int main(void){
  int n=0,x=0,y=0;
  int score=0;
  scanf("%d",&n);
  int dist=0;
  for (int i=0;i<n;i++){
    scanf("%d %d",&x,&y);
    dist=x*x+y*y;
    if(dist<=2*2){
      score+=5;
    }
    else if(dist<=4*4){
      score+=4;
    }
    else if(dist<=6*6){
      score+=3;
    }
    else if(dist<=8*8){
      score+=2;
    }
    else if(dist<=10*10){
      score+=1;
    }
  }
  printf("%d",score);
  return 0;
}