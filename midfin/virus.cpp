#include <bits/stdc++.h>
using namespace std;
vector<int> DNA;
int n,m;


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int val;
        cin >> val;
        DNA.push_back(val);
    }
    auto virus_it = DNA.begin();
    //printf("first virus at %d\n",*virus_it);

    for(int i=0;i<m;i++){
        int t;
        cin >> t;
        if(t==1){
            virus_it = DNA.begin();
        }
        else if(t==2){
            auto tmp = virus_it;
            tmp++;
            if(tmp == DNA.end()){
                virus_it = DNA.begin();

                // for(auto data : DNA){
                //     printf("%d ",data);
                // }
                // printf("virus is %d\n",*virus_it);

                continue;
            }
            virus_it++;
        }
        else if(t==3){
            long long val;
            cin >> val;
            virus_it = DNA.insert(virus_it,val);
            virus_it++;
        }
        else if(t==4){
            long long val;
            cin >> val;
            auto tmp = virus_it;
            tmp++;
            if(tmp == DNA.end()){
                DNA.push_back(val);

                // for(auto data : DNA){
                //     printf("%d ",data);
                // }
                // printf("virus is %d\n",*virus_it);

                continue;
            }
            virus_it = DNA.insert(virus_it+1,val);
            virus_it--;
        }
       
        // for(auto data : DNA){
        //     printf("%d ",data);
        // }
        // printf("virus is %d\n",*virus_it);


        
    }
    for(auto data : DNA){
            printf("%d\n",data);
    }
}