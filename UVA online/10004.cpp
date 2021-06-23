#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int n, m;

bool solve(){
    vector<int> side(n+1, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                        if(!is_bipartite) return false;
                    }
                }
            }
        }
    }

    return is_bipartite;
}

int main(){

    while(scanf("%d", &n ) && n != 0){
        scanf("%d", &m);
        adj.clear();
        adj.resize(n+1);

        for(int i = 0 ; i < m ; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        if(solve()){
            cout << "BICOLORABLE." << endl;
        }
        else{
            cout << "NOT BICOLORABLE." << endl;
        }
    }


    return 0;
}