#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr,int i,int n){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[largest]<arr[l]){
        largest = l;
    }
    if(r<n && arr[largest]<arr[r]){
        largest = r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
}

void heapSort(vector<int>& arr,int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,i,n);

    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}

void print(vector<int>& arr){
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr[i] = num;
    }
    heapSort(arr,n);
    print(arr);
    return 0;
}