// Prims algorithm

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5 + 6;
vector<vector<int>> adjl[N];
int cost = 0;
vector<int> dist(N),parent(N);
const int INF = 1e9;
vector<bool> vis(N);

void prismMST(int source){
	for(int i=0;i<N;i++){
		dist[i] = INF;
	}
	set<vector<int>> s;
	dist[source] = 0;
	s.insert({0,source});
	while(!s.empty()){
		auto x = *(s.begin());
		s.erase(x);
		vis[x[1]] = true;
		int u = x[1];
		int v = parent[x[1]];
		int w = x[0];
		cout<<u<<" "<<v<<endl;
		cost+=w;
		for(auto it:adjl[x[1]]){
			if(vis[it[0]])
				continue;
			if(dist[it[0]]>it[1]){
				s.erase({dist[it[0]],it[0]});
				dist[it[0]] = it[1];
				s.insert({dist[it[0]],it[0]});
				parent[it[0]] = x[1];
			}
		}
	}
	cout<<cost<<endl;
	
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adjl[u].push_back({v,w});
		adjl[v].push_back({u,w});
	}
	prismMST(0);
	return 0;
}