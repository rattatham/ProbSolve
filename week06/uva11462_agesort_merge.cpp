#include <bits/stdc++.h>
using namespace std;

long long mergesort(long long arr[],long long left,long long right);
long long merge(long long arr[],long long left,long long mid,long long right);


int main(){
    long long n=-1;
    long long ans;
    while(n!=0){
        cin >> n;
        if(n==0){
            break;
        }
        long long arr[n];
        for(long long i=0;i<n;i++){
            cin >> arr[i];
        }
        ans = mergesort(arr,0,n-1);


        for(long long i=0;i<n;i++){
            if(i!=n-1)
                cout << arr[i] << " ";
            else
                cout << arr[i];
        }
        cout << endl;

    }
    return 0;
}


long long mergesort(long long arr[],long long left,long long right){
    long long inv_count=0;
    long long mid = left+(right-left)/2;
    if(right>left){
        inv_count+=mergesort(arr,left,mid);
        inv_count+=mergesort(arr,mid+1,right);
        inv_count+=merge(arr,left,mid,right);
    }

    return inv_count;
}


long long merge(long long arr[],long long left,long long mid,long long right){
    long long inv_count=0;
    long long subL = mid-left+1;
    long long subR = right-mid;
    long long L[subL];
    long long R[subR];

    //copy data to tmp arrays L and R
    //L starts from left to left+subL
    //R starts from mid+1 to mid+1+subL
    for(long long i=0;i<subL;i++){
        L[i] = arr[left+i];
    }
    for(long long j=0;j<subR;j++){
        R[j] = arr[mid+1+j];
    }


    //merge L and R 
    long long i=0,j=0;
    long long k = left; // k = ตัวชี้ใน arr เก่า

    /*printf("mid:%d\n",mid);
    cout << "L: ";
    for(int i=0;i<subL;i++){
        printf("%d ",L[i]);
    }
    cout << endl;
    cout << "R: ";
    for(int i=0;i<subR;i++){
        printf("%d ",R[i]);
    }
    cout << endl;*/

    while(i<subL && j<subR){
        //ถ้าข้างซ้ายน้อยกว่าข้างขวา ก็ให้ arr ตัวที่ k = ตัวจาก arr ซ้าย แล้วขยับ i กับ k ไป 1 
        if(L[i]<=R[j]){
            //printf("L:%d < R:%d\n",L[i],R[j]);
            arr[k++] = L[i++];
            
        }
        //ถ้าหากข้างขวาน้อยกว่าซ้าย แปลว่าเกิด inversion = mid-left-i+1
        else{
            //printf("L:%d > R:%d\n",L[i],R[j]);
            //printf("inv+= %d\n",mid-left-i+1);
            arr[k++]  = R[j++];
            inv_count+=mid-left-i+1;
        }
    }
    while(i<subL){
        arr[k++] = L[i++];
    }
    while(j<subR){
        arr[k++] = R[j++];
    }
    //cout << endl;
    return inv_count;
}