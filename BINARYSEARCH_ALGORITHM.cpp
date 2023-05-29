#include <iostream>
using namespace std;

int BinarySearch(int arr[],int n,int key){
    int e=n;
    int s=0;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return -1;
}

int main(){
    //cout<<"Hello World!"<<endl;
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>key;
    cout<<BinarySearch(arr,n,key)<<endl;

}