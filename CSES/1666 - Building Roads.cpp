#include <bits/stdc++.h>

using namespace std;
int n, m;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;


void dfs(int u){

    visited[u] = true;

    for(int i : adj[u]){
        if(!visited[i])
            dfs(i);
    }
}

int main(){

    cin >> n >> m;
    adj.resize(n+1);
    visited.assign(n+1, false);

    int a, b;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int counter = -1;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            counter++;
            ans.push_back(i);
            dfs(i);
        }
    }

    cout << counter;
    if(counter >= 1){
        cout << endl;

        for(int i = 0 ; i < ans.size()-1; i++){
            cout << ans[i] << " " << ans[i+1] << endl;
        }
    }

    return 0;
}