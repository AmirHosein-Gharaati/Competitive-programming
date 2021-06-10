#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
vector<int> path, dist;
const int INF = 1 << 30;

void bfs(){

    queue<int> q;
    q.push(1);
    dist[1] = 0;
 
    while(!q.empty()){
        int current = q.front();
 
        q.pop();
        visited[current] = true;

        for(int next : adj[current]){
            if(dist[current] + 1 < dist[next]){
                q.push(next);
                parent[next] = current;
                dist[next] = dist[current] + 1;
            }
        }
        
    }
    for(int p = n ; p != 1 && p != -1 ; p = parent[p]){
        path.push_back(p);
    }
    path.push_back(1);

    reverse(path.begin(), path.end());

}

int main(){

    cin >> n >> m;
    adj.resize(n+1);
    visited.assign(n+1, false);
    parent.assign(n+1, -1);
    dist.assign(n+1, INF);

    int a, b;
    for(int i = 0 ;i < m ;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    bfs();
    
    if(dist[n] != INF){
        cout << path.size() << endl;
        for(int ans : path) cout << ans << " ";
    }
    else{
        cout << "IMPOSSIBLE";
    }


    return 0;
}