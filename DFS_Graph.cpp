// Graph representation using adjacency matrix
// Graph representation using adjacency list

#include<bits/stdc++.h> 
using namespace std;

// n = number of nodes 
// m = number of edges
const int N = 1e5+2;
vector<int> adjl[N];
vector<bool> vis(N,false);
//vis.resize(N,false);

void dfs(int node){
	//preorder
	vis[node]=1;
	cout<<node<<" ";
	//inorder
	for(int x:adjl[node]){
		if(vis[x]);
		else{
			dfs(x);
		}
	}
	//preorder
	// vis[node]=1;
	// cout<<node<<" ";
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adjl[x].push_back(y);
		adjl[y].push_back(x);
	}
	dfs(1);
	// stack<int> st;
	// st.push(1);
	// vis[1] = 1;
	// while(!st.empty()){
	// 	int node = st.top();
	// 	cout<<node<<" ";
	// 	st.pop();
	// 	for(int x:adjl[node]){
	// 		if(!vis[x]){
	// 			st.push(x);
	// 		}
	// 	}
	}
    return 0;
}