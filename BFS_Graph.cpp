// Graph representation using adjacency matrix
// Graph representation using adjacency list

#include<bits/stdc++.h> 
using namespace std;

// n = number of nodes 
// m = number of edges

const int N = 1e5+2;
bool vis[N];
vector<int> adjl[N];
int main(){
    for(int i=0;i<N;i++)
		vis[i] = 0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adjl[x].push_back(y);
		adjl[y].push_back(x);
	}
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cout<<node<<endl;
		for(int x:adjl[node]){
			if(!vis[x]){
				q.push(x);
			}
		}
	}
    return 0;
}