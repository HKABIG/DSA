// Graph representation using adjacency matrix
// Graph representation using adjacency list

#include<bits/stdc++.h> 
using namespace std;

// n = number of nodes 
// m = number of edges

const int N = 1e5+2;
vector<int> adjl[N];
int main(){
    // int n,m;
	// cin>>n>>m;
	// vector<vector<int>> adjm(n+1,vector(n+1,0));
	// for(int i=0;i<m;i++){
	// 	int x,y;
	// 	cin>>x>>y;
	// 	adjm[x][y] = 1;
	// 	adjm[y][x] = 1;
	// }
	// cout<<"adjacency matrix of the above graph is:"<<endl;
	// for(int i=1;i<n+1;i++){
	// 	for(int j=1;j<n+1;j++){
	// 		cout<<adjm[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adjl[x].push_back(y);
		adjl[y].push_back(x);
	}
	for(int i=1;i<n+1;i++){
		cout<<i<<"->";
		for(int x:adjl[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	
    return 0;
}