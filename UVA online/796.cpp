#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
int n;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
int timer;
vector<ii> ans;


void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                ans.push_back({min(to, v), max(to ,v)});
            }
                
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}




int main(){

    while(scanf("%d", &n) != EOF){
        
        adj.clear();
        adj.resize(n);


        for(int i = 0 ; i < n ; i++){
            int a;
            int tt;
            int next;
            scanf("%d (%d)", &a, &tt);

            while(tt--){
                scanf("%d", &next);
                adj[a].push_back(next);
            }
        }

        find_bridges();
        sort(ans.begin(), ans.end());

        cout << ans.size() << " critical links" << endl;

        for(int i = 0 ; i < ans.size() ; i++){
            cout <<  ans[i].first << " - " << ans[i].second << endl;
        }
        cout << endl;
    }


    return 0;
}