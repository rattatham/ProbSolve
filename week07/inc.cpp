#include <bits/stdc++.h>
using namespace std;

int arr[100010];
//tmp vector for saving subsequence
//tail will store indexs of numbers in arr
//save will save second most of a subsequence of i
vector<int> tail(100010,0);
vector<int> save(100010,-1);
//note that tail will save the indexs in reverse order
list<int> ans;


int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int len=1;
    for(int i=0;i<n;i++){
        //new smallest value
        if(arr[i]<=arr[tail[0]]){
            //save its index
            tail[0] = i;
        }

        //finding new largest for a subsequence
        else if (arr[i]>arr[tail[len-1]]){
            //save index of second most value from tail to save of that subsequence
            save[i]=tail[len-1];
            //change largest value to index i
            tail[len]=i;
            //extending our subsequence len
            len++;
        }

        //new subsequence (when arr[i] <= tail[len-1])
        else{
            //binary search for **index** of arr[i] in tail
            int left = -1;
            int right = len-1;
            while( right - left > 1){
                int mid = left+(right-left)/2;
                if(arr[tail[mid]] >= arr[i]){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            int pos = right;
            //change subsequence
            save[i] = tail[pos-1];
            tail[pos] = i;
        }
        
    }
    int count=0;
    for(int i=tail[len-1];i!=-1;i=save[i]){
        //cout << arr[i] << " ";
        ans.push_back(arr[i]);
    }
    //printf("ans\n");
    ans.reverse();
    cout << len;
    cout << endl;
    for(auto v : ans){
        cout << v << " ";
    }
    
}