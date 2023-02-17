//deducing the array
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[]={10,16,19,1,5,8,34,3,9,2};
	vector <pair<int,int>> v;
	for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
	    //v.push_back(make_pair(arr[i],i)); 
	    pair <int,int> p;
	    p.first=arr[i];
	    p.second=i;
	    v.push_back(p);
	}
	sort(v.begin(),v.end()); 
	for(int i=0;i<v.size();i++){
	    arr[v[i].second]=i;
	}
	for(int i=0;i<v.size();i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}