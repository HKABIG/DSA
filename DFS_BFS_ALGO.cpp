// BFS DFS
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5+7;
vector<int> adjl[N];
vector<bool> visited(N,false);

void BFS(int s){
    vector<bool> vis(N,false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int n = q.front();
        cout<<n<<" ";
        q.pop();
        for(int x:adjl[n]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
}

void DFS(int s){
	cout<<s<<" ";
    visited[s] = true;
    for(auto x:adjl[s]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

void itDFS(int s){
    vector<bool> vis(N,false);
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int n = st.top();
        st.pop();
        if(!vis[n]){
            vis[n] = true;
            cout<<n<<" ";
        }
        for(auto it:adjl[n]){
            if(!vis[it]){
                st.push(it);
		}
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    BFS(2);
    cout<<endl;
    DFS(2);
    cout<<endl;
    itDFS(2);
}