#include <bits/stdc++.h>
using namespace  std;

char name[110];
char text='a';
list<char> q;
list<char> nameq;
char cmp;

int main(void){
    scanf("%s ",name);
    for(int i=0;i<strlen(name);i++){
        q.push_back(name[i]);
        nameq.push_back(name[i]);
    }
    int ans=0;
    while(text!='\n'){
        scanf("%c",&text);
        cmp=q.front();
        if(text==cmp){
            q.pop_front();
            if(q.empty()){
                ans++;
                q=nameq;
            }
        }
    }
    cout << ans;

    return 0;
}