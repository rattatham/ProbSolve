#include <bits/stdc++.h>
using namespace std;
list<char> output;
int main(void){
    char keyboard[100100];
    while(cin >> keyboard){
        list<char>::iterator it;
        int kb_len=strlen(keyboard);
        output.clear();
        it=output.begin();
        for(int i=0;i<kb_len;i++){
            if(keyboard[i]=='['){
                it=output.begin();
            }
            else if(keyboard[i]==']'){
                it=output.end();
            }
            else{
                output.insert(it,keyboard[i]);
            }
        }
        for(it=output.begin();it!=output.end();it++){
            cout<<*it;
        }
        cout << endl;
    }
    return 0;
}