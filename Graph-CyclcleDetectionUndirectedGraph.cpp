// Graph - Cycle detection in undirected Graph

#include<bits/stdc++.h> 
using namespace std;

// n = number of nodes 
// m = number of edges
// const int N = 1e5+2;
// vector<int> adjl[N];
// vector<bool> vis(N,false);
//vis.resize(N,false);

bool iscycle(int src,vector<vector<int>>& adjl,vector<bool>& visited,vector<int>& stack){
		stack[src] = true;
		if(!visited[src]){
			visited[src] = true;
			for(auto i:adjl[src]){
				if(!visited[i] and iscycle(i,adjl,visited,stack)){
					return true;
				}
				if(stack[i])
					return true;
			}
		}
		stack[src] = false;
		return false;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adjl(n);
	vector<int> in_deg(n,0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adjl[x].push_back(y);
	}
	bool cycle = false;
	vector<bool> visited(n,false);
	vector<int> stack(n,0);
	for(int i=0;i<n;i++){
		if(!visited[i] && iscycle(i,adjl,visited,stack)){
			cycle = true;
		}
	}
	if(cycle){
		cout<<"Cycle is present"<<endl;
	}
	else{
		cout<<"Cycle is not present"<<endl;
	}
}