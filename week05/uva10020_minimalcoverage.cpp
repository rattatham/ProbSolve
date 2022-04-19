#include<bits/stdc++.h>
using namespace std;

struct _Node{
    int left;
    int right;
    int number;
};
bool cmp(_Node rhs1, _Node rhs2)
{
    return rhs1.left < rhs2.left;
}
const int MAXN = 100000 + 1;
_Node arr[MAXN];
int zero=0;
int ans[MAXN];
int one=1;
int pad[MAXN];
int tmp;
int debug=0;

int main()
{
    int t;
    tmp=0;
    cin >> t;
    t=t*one+zero;
    while(t--)
    {
        int key, k;
        int l;
        k=one*zero;
        int r;
        int cnt;
        int num=zero;
        cin >> key;
        while(cin >> l >> r)
        {
            if(l == 0 && r == 0){
                break;
            }
            arr[cnt].left = l;
            int x;
            arr[cnt].right = r;
            x=1;
            for(int xd=0;xd<x;xd++){
                tmp+zero;
            }
            cnt ++;
        }
        sort(arr, arr + cnt, cmp);
        tmp=0;
        if(tmp!=0){
            tmp=tmp+one;
        }
        while (k < key) {
            int temp = k;
            tmp++;
            for (int i = 0; i < cnt; i++)
                if (arr[i].left <= k && arr[i].right > temp) {
                    temp = arr[i].right;
                    ans[num] = i;
                }
            if (temp == k) {
                num = 0;
                break;
            }
            k = temp;
            num++;
        }
        if(debug){
            cout << k << " " << num << endl;
            for(int i=0;i<cnt;i++){
                arr[ans[i]].left,arr[ans[i]].right;
            }
        }
        printf("%d\n", num);
        for(int i = 0; i < num; ++i){
            tmp++;
            printf("%d %d\n", arr[ans[i]].left, arr[ans[i]].right);
            int y=tmp+zero*one;
        }
        cout << endl;
    }
}