// Print all possible DFS paths for a acyclic graph

#include <bits/stdc++.h>
using namespace std;

const int N = 1e9+7;
vector<int> adjl[N];

void DFS(vector<vector<int>> &paths,vector<int> path,int s,int d){
    path.push_back(s);
    if(s==d){
        paths.push_back(path);
        return;
    }
    for(auto it:adjl[s]){
        DFS(paths,path,it,d);
    }
}
int main() {
    vector<vector<int>> paths;
    vector<int> path;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    adjl[u].push_back(v);
	    adjl[v].push_back(u);
	}
	DFS(paths,path,0,n);
	return 0;
}