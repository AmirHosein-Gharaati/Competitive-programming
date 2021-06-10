#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> adj;
vector<bool> visited;
set<int> a, b;
bool flag = true;
vector<int> ans;


void dfs(int u){

    visited[u] = true;
    if(a.find(u) == a.end() && b.find(u) == b.end()){
        a.insert(u);
        ans[u] = 1;
    }

    for(int next : adj[u]){

        if(a.find(u) != a.end() && a.find(next) == a.end() && b.find(next) == b.end()){
            b.insert(next);
            ans[next] = 2;
            dfs(next);
        }
        else if(b.find(u) != b.end() && a.find(next) == a.end() && b.find(next) == b.end()){
            a.insert(next);
            ans[next] = 1;
            dfs(next);
        }
        else if((a.find(next) != a.end() && a.find(u) != a.end()) || (b.find(next) != b.end() && b.find(u) != b.end())){
            flag = false;
            return;
        }
        
        
    }



}

int main(){

    cin >> n >> m;
    adj.resize(n+1);
    visited.assign(n+1, false);
    ans.assign(n+1, -1);

    int a, b;
    for(int i = 0 ; i < m ;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        if(!visited[i])
            dfs(i);
    }

    if(flag){
        for(int i = 1 ; i <= n ; i++){
            cout << ans[i] << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
    
    return 0;
}