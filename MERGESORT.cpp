#include <bits/stdc++.h> 
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;//First Half
    int n2 = r - mid;//Second Half 
    int a[n1];
    int b[n2];//Temporary arr 
    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(a[i]<b[j]){ // Sorting the first half wiht second half
            arr[k] = a[i];
            k++; i++;
        }
        else{
            arr[k] = b[j];
            k++; j++;
        }
    }
    while(i<n1){
        arr[k] = a[i];//Adding the remaining elements which didn't come into picture
        k++; i++;
    }
    while(j<n2){
        arr[k] = b[j];//Adding the remaining elements which didn't come into picture
        k++; j++;
    }
    
} 

void mergeSort(int arr[], int l, int r){
    int mid = (l + r) / 2 ;
    if(l < r){//Stop Condition
        mergeSort(arr,l,mid);//Dividing the arr from 1st to middle
        mergeSort(arr,mid+1,r);//Dividing the arr form middle
        merge(arr,l,mid,r);//Merging the divided arr
    }
    

} 

int main(){
    int arr[]  = {5,4,3,2,1};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}