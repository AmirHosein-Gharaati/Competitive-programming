#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);

vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order;

void dfs1(int u){

    visited[u] = true;

    for(int next : adj[u]){
        if(!visited[next]){
            dfs1(next);
        }
    }
    order.push_back(u);
}

void dfs2(int u){

    visited[u]= true;

    for(int next : adj_rev[u]){
        if(!visited[next]){
            dfs2(next);
        }
    }
}

int main(){

    fast;

    int tt;
    cin >> tt;

    while(tt--){
        int n, m;
        cin >> n >> m;

        adj.clear();
        adj.resize(n+1);

        adj_rev.clear();
        adj_rev.resize(n+1);

        for(int i = 0 ; i < m ;i++){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj_rev[b].push_back(a);
        }

        visited.clear();
        visited.assign(n+1, false);

        order.clear();
        for(int i = 1 ; i <= n ; i++){
            if(!visited[i]){
                dfs1(i);
            }
        }

        visited.assign(n+1, false);

        reverse(order.begin(), order.end());

        int counter = 0;
        for(int a = 0 ; a < n ; a++){
            if(!visited[order[a]]){
                counter++;
                dfs1(order[a]);
            }
        }

        cout << counter << endl;
    }


    return 0;
}