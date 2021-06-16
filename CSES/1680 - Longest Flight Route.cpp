#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> adj;
vector<int> dist, parent;
vector<bool> visited;
stack<int> s;
int n, m;
bool isDone = false;
 
void dfs(int u){

    visited[u] = true;

    for(int next : adj[u]){
        if(!visited[next]){
            dist[next] = dist[u]+1;
            parent[next] = u;
            dfs(next);
        }
    }

    s.push(u);
 
}
 
int main(){
 
    cin >> n >> m;
 
    adj.resize(n+1);
    parent.assign(n+1, -1);
    dist.assign(n+1, 0);
    visited.assign(n+1, false);
 
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >>a >> b;
        adj[a].push_back(b);
    }
 
    dfs(1);
 
    if(visited[n]){

        while(!s.empty()){
            int current = s.top();
            s.pop();

            for(int next : adj[current]){
                if(dist[current] + 1 > dist[next]){
                    dist[next] = dist[current] + 1;
                    parent[next] = current;
                }
            }
        }
    
        vector<int> ans;
        for(int x = n ; x != 1 ; x = parent[x]){
            ans.push_back(x);
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
 
        cout << ans.size() << endl;
        for(int u : ans) cout << u << " ";
    }
    else{
        cout << "IMPOSSIBLE";
    }
    return 0;
}