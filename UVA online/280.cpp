#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u){

    for(int i : adj[u]){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
}


int main(){


    int n;
    while(scanf("%d", &n) && n != 0){  
        adj.clear();
        adj.resize(n+1);

        visited.clear();
        
        int node;
        while(scanf("%d", &node) && node != 0){
            int to;
            while(scanf("%d", &to) && to != 0){
                adj[node].push_back(to);
            }
        }

        int tt;
        scanf("%d", &tt);
        while(tt--){
            int number;
            vector<int> result;
            visited.assign(n+1, false);
            result.clear();

            scanf("%d", &number);
            dfs(number);
            for(int i = 1 ; i <= n ; i++){
                if(!visited[i])
                    result.push_back(i);
            }
            cout << result.size();
            if(result.size() != 0) cout << " ";
            for(int i = 0 ; i < result.size() ; i++){
                cout << result[i];
                if(i != result.size()-1) cout << " ";
            }
            cout << endl;
        }
        
    }


    return 0;
}