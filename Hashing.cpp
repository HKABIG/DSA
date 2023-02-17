#include <bits/stdc++.h>
using namespace std;

#define TABLE_SIZE 10 

int h[TABLE_SIZE] = {NULL};

void insert(){
	int key,index,i,hkey;
	cin>>key;
	hkey = key%TABLE_SIZE;
	for(i=0;i<TABLE_SIZE;i++){
		index = (hkey + i)%TABLE_SIZE;
		if(h[index]==NULL){
			h[index] = key;
			cout<<"Element has been inserted"<<endl;
			break;
		}
	}
	if(i==TABLE_SIZE)
		cout<<"Element cannot be inserted"<<endl;
}

void search(){
	int key,index,i,hkey;
	cout<<"Enter the element to be searched"<<endl;
	cin>>key;
	int key,index,i,hkey;
	cout<<"Enter the element to be searched"<<endl;
	cin>>key;
	hkey = key%TABLE_SIZE;
	for(i=0;i<TABLE_SIZE;i++){
		index = (hkey + i)%TABLE_SIZE;
		if(h[index]==key){
			cout<<"Value->"<<key<<" "<<"is found at "<<index<<endl;
			break;
		}
	}
	if(i==TABLE_SIZE)
		cout<<"Value not found"<<endl;
}

void display(){
	int i;
	for(i=0;i<TABLE_SIZE;i++)
		cout<<i<<"->"<<h[i]<<endl;
}

int main()
{
    	int n,c;
	do{
		cout<<"Choose 1 for insert:"<<endl;
		cout<<"Choose 2 for display:"<<endl;
		cout<<"Choose 3 for search:"<<endl;
		cin>>c;
		switch(c){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
		}
		cout<<"Enter 1 to continue"<<endl;
		cin>>n;
	}while(n==1);
}
