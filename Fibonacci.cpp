#include <iostream>
using namespace std;

void fibonacciSearch(int arr[],int n,int x){
	int fibm2 = 0;
	int fibm1 = 1;
	int fibm = fibm1+fibm2;
	while(fibm<n){
		fibm2 = fibm1;
		fibm1 = fibm;
		fibm = fibm2 + fibm1;
	}
	int offset = -1;
	while(fibm>1){
		int i = min(offset+fibm2,n-1);
		if(arr[i]<x){
			// Going one fibonacci variable down
			fibm = fibm1;// mth = (m-1)th
			fibm1 = fibm2;// (m-1)th = (m-2)th
			fibm2 = fibm - fibm1;// (m-2)th = (m)th - (m-1)th = (m-1)th - (m-2)th
			offset = i;
		}
		else if(arr[i]>x){
			// Going two fibonacci variable down
			fibm = fibm2;// mth = (m-2)th
			fibm1 = fibm1 - fibm2;// (m-1)th = (m-1)th - (m-2)th
			fibm2 = fibm - fibm1;// (m-2)th = (m)th - (m-1)th 
			}
		else{
			cout<<"element is found at "<<i<<endl;
			return ;
		}
	}
	if(fibm1 && arr[offset + 1]==x){
		cout<<"element is found at "<<offset+1<<endl;
		return;
	}
	cout<<"element is not found "<<endl;
	return ;
}

int main() {
	cout<<"Enter the size of array: "<<endl;
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the element to be searched:"<<endl;
	int x;
	cin>>x;
	fibonacciSearch(arr,n,x);
	
}