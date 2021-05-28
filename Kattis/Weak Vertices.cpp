#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool visited[30];
vector<int> ans;

bool is_neighbour(int source, int dest){
    return (find(adj[source].begin(), adj[source].end(), dest) != adj[source].end());
}


void dfs(int u){
    visited[u] = true;

    for(int i = 0 ; i < adj[u].size(); i++){
        for(int j = i+1 ; j < adj[u].size(); j++){
            if(is_neighbour(adj[u][i], adj[u][j]) && is_neighbour(adj[u][j], adj[u][i])){
                ans[u] = false;
            }
        }
    }

    for(int i : adj[u]){
        if(!visited[i])
            dfs(i);
    }
}


int main(){


    int n;
    while(scanf("%d", &n) && n != -1){
        memset(visited, false, sizeof(visited));
        adj.clear(); adj.resize(n);
        ans.clear(); ans.assign(n, true);
        int temp;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> temp;
                if(temp == 1){
                    adj[i].push_back(j);
                }
            }   
        }

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        for(int i = 0 ; i < n ;i++){
            if(ans[i])
                cout << i << " ";
        }
        cout << endl;
    }


    return 0;
}