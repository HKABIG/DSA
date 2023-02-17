#include<bits/stdc++.h>
using namespace std;

void Array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void InsertionSort(int n,int arr[]){
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j>=0 && arr[j]>key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void Merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int k=l;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++; i++;

    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

void MergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        Merge(arr,l,mid,r);
    }

}

int BinarySearch(int arr[],int n){
    int key;
    cin>>key;
	bool f = false;
    int l,h,mid;
    l = 0;
    h = n-1;
    mid=l+h/2;
    while(l<=h){
        if(key==arr[mid]){
            cout<<mid<<endl;
			f = true;
            break;
        }
        else if(key<arr[mid]){
            mid=mid+1;
            l++;
        }
        else{
            mid=mid-1;
            l++;
        }
    }
	if(!f){
    cout<<"ELEMENT NOT FOUND"<<endl;
	}

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int e;
    cin>>e;
    switch(e){
    case 1:
        MergeSort(arr,0,n-1);
        Array(arr,n);
    case 2:
        InsertionSort(n,arr);
        Array(arr,n);
    case 3:
        BinarySearch(arr,n);
	default:
		cout<<"YOU HAVE EXITED"<<endl;
		break;
    }
}
