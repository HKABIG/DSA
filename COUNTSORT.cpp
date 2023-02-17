#include<bits/stdc++.h> 
using namespace std;

void CounSort(int arr[],int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;//Count Array
    }
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];//Position Array //Prefix Array
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main(){
    int arr[]={1,2,5,5,5,8,9,8,5,6};
    CounSort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}