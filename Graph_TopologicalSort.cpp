// Graph - Topological Sort

#include<bits/stdc++.h> 
using namespace std;

// n = number of nodes 
// m = number of edges
// const int N = 1e5+2;
// vector<int> adjl[N];
// vector<bool> vis(N,false);
//vis.resize(N,false);

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adjl(n);
	vector<int> in_deg(n,0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adjl[x].push_back(y);
		in_deg[y]++;
	}
	queue<int> q;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(in_deg[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		cnt++;
		int u = q.front();
		q.pop();
		cout<<u<<" ";
		for(auto it:adjl[u]){
			in_deg[it]--;
			if(in_deg[it]==0){
				q.push(it);
			}
		}
}
}