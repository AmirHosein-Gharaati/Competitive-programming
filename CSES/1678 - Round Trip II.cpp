#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> ans, parent;
vector<int> visited;
const int INF = 1e6;

void dfs(int u){

    visited[u] = 1;
    
    for(int next : adj[u]){

        if(visited[next] == 0){
            parent[next] = u;
            dfs(next);
        }   

        else if (visited[next] == 1){
            ans.clear();
            ans.push_back(next);

            for(int j = u ; j != next ; j = parent[j]){
                ans.push_back(j);
            }

            ans.push_back(next);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for(int a : ans) cout << a << ' ';
            exit(0);
        }
    }

    visited[u] = 2;
    return;

}

int main(){

    cin >> n >> m;
    visited.assign(INF, 0);
    parent.assign(INF, -1);
    adj.resize(INF);

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1 ; i <= n ;i++){
        if(visited[i] == 0)
            dfs(i);
    }
    cout << "IMPOSSIBLE";

    return 0;
}