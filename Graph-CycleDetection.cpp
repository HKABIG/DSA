// Graph - Cycle detection in undirected Graph

#include<bits/stdc++.h> 
using namespace std;

// n = number of nodes 
// m = number of edges
// const int N = 1e5+2;
// vector<int> adjl[N];
// vector<bool> vis(N,false);
//vis.resize(N,false);

bool iscycle(int src,vector<vector<int>>& adjl,vector<bool>& visited,int parent){
		visited[src] = true;
		for(auto i:adjl[src]){
			if(i!=parent){
				if(visited[i])
					return true;
				if(!visited[i] && iscycle(i,adjl,visited,-1)){
						return true;	
				}
			}
		}
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
		adjl[y].push_back(x);
	}
	bool cycle = false;
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i] && iscycle(i,adjl,visited,-1)){
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