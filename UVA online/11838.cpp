#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj, adj_reverse;
vector<bool> visited;
vector<int> order;

void dfs1(int u){

    visited[u] = true;

    for(int next : adj[u]){
        if(!visited[next]){
            dfs1(next);
        }
    }

}

void dfs2(int u){

    visited[u] = true;

    for(int next : adj_reverse[u]){
        if(!visited[next])
            dfs2(next);
    }
}

int main(){


    int n, m;
    while(scanf("%d %d", &n, &m) && n+m != 0){
        adj.clear();
        adj.resize(n+1);

        adj_reverse.clear();
        adj_reverse.resize(n+1);

        visited.clear();
        visited.assign(n+1, false);

        for(int i = 0 ; i < m ; i++){
            int a, b, c;
            cin >> a >> b >> c;
            if(c == 1){
                adj[a].push_back(b);

                adj_reverse[b].push_back(a);
            }
            else if(c == 2){
                adj[a].push_back(b);
                adj[b].push_back(a);

                adj_reverse[a].push_back(b);
                adj_reverse[b].push_back(a);
            }
        }

        int counter;

        counter = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!visited[i]){
                counter++;
                dfs1(i);
                if(counter >= 2) break;
            }
        }
        if(counter >= 2){
            cout << 0 << endl;
            continue;
        }

        visited.assign(n+1, false);

        counter = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!visited[i]){
                counter++;
                dfs2(i);
                if(counter >= 2) break;
            }
        }

        if(counter == 1) cout << 1 << endl;
        else cout << 0 << endl;

    }



    return 0;
}