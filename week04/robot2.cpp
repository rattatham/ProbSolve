#include <iostream>

using namespace std;

int main(void){
    char walk[110];
    int state=0;
    scanf("%s",walk);
    for(int i=0;i<100;i++){
        //printf("%d",state);
        if(walk[i]=='N'){
            while(state!=0){
                state+=1;
                state=state%4;
                printf("R");
            }
            printf("F");
        }
        else if(walk[i]=='E'){
            while(state!=1){
                state+=1;
                state=state%4;
                printf("R");
            }
            printf("F");
        }
        else if(walk[i]=='S'){
            while(state!=2){
                state+=1;
                state=state%4;
                printf("R");
            }
            printf("F");
        }
        else if(walk[i]=='W'){
            while(state!=3){
                state+=1;
                state=state%4;
                printf("R");
            }
            printf("F");
        }
        else if(walk[i]=='Z'){
            state=0;
            printf("Z");
        }
    }
    return 0;
}