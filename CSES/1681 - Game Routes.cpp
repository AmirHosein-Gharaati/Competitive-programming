#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> adj;
vector<bool> visited, can_solve;
vector<int> counter;
stack<int> s;
const int mod = 1e9 + 7;

bool dfs(int u){

    visited[u] = true;
    

    if(u == n){
        return true;
    }

    for(int next : adj[u]){
        if((!visited[next] && dfs(next)) || can_solve[next]){
            can_solve[next] = true;
            can_solve[u] = true;
        }
            
        
    }
    s.push(u);
    return can_solve[u];
}

int main(){

    cin >> n >> m;
    adj.resize(n+1);
    visited.assign(n+1, false);
    counter.assign(n+1, 0);
    can_solve.assign(n+1, false);

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);
    counter[1] = 1;
    while(!s.empty()){
        int v = s.top();
        s.pop();

        for(int next : adj[v]){
            if(can_solve[next]){
                counter[next] = (counter[next]+counter[v])%mod;
            }
        }
    }

    cout << counter[n];
    return 0;
}