#include <bits/stdc++.h>

using namespace std;

#define MAX 10010
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;

    for(auto next : adj[u]){
        if(!visited[next])
            dfs(next);
    }
}

int main() {

    int tt;
    cin >> tt;

    while(tt--){
        int n, m, l;
        cin >> n >> m >> l;
        adj = vector<vector<int>>(n+1);
        visited = vector<bool>(n+1, false);

        for(int i = 0 ; i < m ; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        for(int i = 0 ; i < l ; i++){
            int a;
            cin >> a;
            dfs(a);
        }

        int counter = 0;

        for(int i = 1 ; i <= n ;i++){
            if(visited[i]) counter++;
        }

        cout << counter << endl;
    }

    return 0;
}