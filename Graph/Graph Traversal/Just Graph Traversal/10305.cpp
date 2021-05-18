#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int> > adj;
vector<int> ans;


void dfs(int u){
    visited[u] = true;
    int v;
    for(unsigned i = 0; i < adj[u].size(); ++i) {
        v = adj[u][i];
        if(!visited[v]) dfs(v);
    }
    ans.push_back(u);
}

void topo_sort(int n){
    for(int i = 1; i <= n; ++i) {   
        if(!visited[i]) dfs(i);
    }

    reverse(ans.begin(), ans.end());
}


int main(){

    int n, m;

    while(cin >> n >> m, n != 0 || m != 0) {
        visited.clear();
        visited.assign(n+1, 0);
        adj.clear();
        adj.resize(n+1);
        ans.clear();
        int u, v;

        while(m--) {                    
            cin >> u >> v;
            adj[u].push_back(v);
        }

        topo_sort(n);

        for(int i = 0; i < n ; i++) { 
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}