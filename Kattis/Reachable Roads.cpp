#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;

    for(int i : adj[u]){
        if(!visited[i])
            dfs(i);
    }
}

int main(){

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        adj.resize(n);
        visited.assign(n, false);


        int e;
        cin >> e;
        for(int i = 0 ; i < e ; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int counter = -1;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                counter++;
                dfs(i);
            }
        }

        cout << counter << endl;

    }




    return 0;
}