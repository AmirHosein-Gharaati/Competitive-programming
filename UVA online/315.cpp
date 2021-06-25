#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> adj;
int timer, counter;
vector<bool> visited;
vector<int> tin, low;
set<int> s;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                s.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        s.insert(v);
}

void find_cutpoints() {
    timer = 0;
    counter = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while(cin >> n && n != 0){
        int a;
        adj.clear();
        adj.resize(n+1);
        s.clear();

        while(cin >> a && a != 0){
            stringstream sin;
            string line;
            int next;

            sin.clear();
            getline(cin, line);
            // cout << line << endl;
            sin << line;
            while(sin >> next){
                adj[a].push_back(next);
                adj[next].push_back(a);
            }
        }

        find_cutpoints();
        cout << s.size() << endl;

    }

    return 0;
}