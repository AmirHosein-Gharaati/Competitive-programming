#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> visited, ans;
int n, m;

void dfs(int u){

    visited[u] = 1;

    for(int next : adj[u]){
        if(visited[next] == 0){
            dfs(next);
        }

        else if(visited[next] == 1){
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }

    visited[u] = 2;
    ans.push_back(u);

}

void topological_sort(){

    for(int i = 1 ; i <=n ; i++){
        if(visited[i] == 0)
            dfs(i);
    }

    reverse(ans.begin(), ans.end());

}


int main(){

    cin >> n >> m;
    adj.resize(n+1);
    visited.assign(n+1, 0);

    
    for(int i =0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }


    topological_sort();

    for(int a : ans) cout << a << " ";


    return 0;
}