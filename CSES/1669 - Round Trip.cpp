#include <bits/stdc++.h>
 
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
 
void dfs(int current, int p){
	visited[current] = true;
	parent[current] = p;
 
	for(int j = 0 ; j < adj[current].size() ; j++ ){
		int u = adj[current][j];
 
		if(visited[u] && p != u){
			vector<int> path;
			path.clear();
			path.push_back(u);
			for(int i = current ; i != u ; i = parent[i]){
				path.push_back(i);
			}
			path.push_back(u);
			reverse(path.begin(), path.end());
			if(path.size() < 4) continue;
			cout << path.size() << endl;
			for(int ans : path) cout << ans << " ";
			exit(0);
		}
		else if(!visited[u]){
			dfs(u, current);
		}
	}
	return;
}
 
int main(){
 
	cin >> n >> m;
	adj.resize(n+1);
	visited.assign(n+1, false);
	parent.assign(n+1, -1);
 
	for(int i = 0 ; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	
	for(int i = 1 ; i <= n ; i++){
		if(!visited[i]){
			dfs(i, -1);
		}
	}
 
	cout << "IMPOSSIBLE";
	return 0;
}