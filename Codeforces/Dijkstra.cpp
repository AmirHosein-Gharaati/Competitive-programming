#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
vector<vector<ii>> adj;
vector<int> dist, parent;
vector<bool> visited;
int n, m;

bool dijkstra(int source){

    dist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, source});
    while(!q.empty()){
        int next = q.top().second;
        q.pop();

        if(next == n) return true;

        visited[next] = true;
        
        for(auto edge : adj[next]){
            int to = edge.second;
            int len = edge.first;

            if(!visited[to] && dist[next] + len < dist[to] ){
                dist[to] = dist[next] + len;
                parent[to] = next;
                q.push({dist[to], to});
            }
        }
    }
    return false;
}

int main(){

    
    cin >> n >> m;
    adj.resize(n+2);
    dist.assign(n+2, INT_MAX);
    parent.assign(n+2, -1);
    visited.assign(n+2, false);
    
    int source, dest, weight;
    for(int i = 0 ; i < m ; i++){
        cin >> source >> dest >> weight;
        adj[source].push_back(make_pair(weight, dest));
        adj[dest].push_back(make_pair(weight,source));
    }

    if(dijkstra(1)){
        vector<int> path;

        for(int v = n; v != -1; v = parent[v]) path.push_back(v);

        for(int i = path.size()-1; i > 0; --i) printf("%d ", path[i]);

        printf("%d", path[0]);
    }
    else{
        cout << -1;
    }
    


    return 0;
}