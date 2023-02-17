#include<bits/stdc++.h>
using namespace std;

void wavesort(int arr[],int n){
    for(int i=1;i<=n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    wavesort(arr,n);
}