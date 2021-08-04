#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int counter;

void dfs(int i){

    visited[i] = true;
    counter++;

    for(int next : adj[i]){
        if(!visited[next]){
            dfs(next);
        }
    }    
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int tt;
    cin >> tt;

    while(tt--){
        
        int n, m, l;
        cin >> n >> m >> l;

        adj.clear();
        adj.resize(n+1);

        for(int i = 0 ; i < m ; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        vector<int> starts;
        starts.clear();
        for(int i = 0 ; i < l ; i++){
            int a;
            cin >> a;
            starts.push_back(a);
        }

        visited.clear();
        visited.assign(n+1, false);
        counter = 0;
        for(int num : starts){
            if(!visited[num]){
                dfs(num);
            }
        }

        cout << counter << endl;
    }



    return 0;
}