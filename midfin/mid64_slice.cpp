#include <bits/stdc++.h>
using namespace std;
int ans[500010];
int wood[500010];
int save=0;
int tmp=0;
int tmp_save=0;

int main(){
    int n;
    cin >> n;

    //init()
    for(int dum=0;dum<500010;dum++){
        wood[dum]=0;
        ans[dum]=0;
    }

    for(int i=1;i<n+1;i++){
        int height;
        cin >> height;
        //if height > save we run up from wood[save+1] to wood[height] = index that time
        if(height>save){
            for(int j=save+1;j<height+1;j++){
                wood[j] = i;
                //printf("save[%d] = %d\n",j,i);
            }
        }

        //if height == save we skipped it
        else if (height==save){
            continue;
        }

        //we start counting wood size when height<save
        else if(height<save){
            for(int j=height+1;j<=save;j++){
                if(ans[i-wood[j]]==0){
                    //printf("new wood number %d\n",i-wood[j]);
                    tmp++;
                }
                ans[i-wood[j]]++;
                
                //printf("ans[%d - wood[%d]] = ans[%d-%d]++\n",i,j,i,wood[j]);
            }
        }
        save=height;
    }

    //clear the remaining wood
    for(int j=1;j<=save;j++){
        if(ans[n+1-wood[j]]==0){
            //printf("new wood number %d\n",n+1-wood[j]);
            tmp++;
        }
        ans[n+1-wood[j]]++;
        //printf("ans[%d - wood[%d]] = ans[%d-%d]++\n",n+1,j,n+1,wood[j]);
    }


    cout << tmp << endl;
    for(int i=0;i<500010;i++){
        if(ans[i]!=0)
            printf("%d %d\n",i,ans[i]);
    }
    return 0;
}