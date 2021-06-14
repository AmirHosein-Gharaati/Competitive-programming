#include <bits/stdc++.h>
 
using namespace std;
typedef pair<int, long> ii;
typedef pair<long, int> new_ii;
 
vector<vector<ii>> adj;
vector<long> dist;
vector<bool> visited;
const int INF = -1;
int n, m;
 
void dijkstra(){
 
 
    priority_queue<new_ii, vector<new_ii>, greater<new_ii>> q;
    q.push({0, 1});
    dist[1] = 0;
 
    while(!q.empty()){
        int current = q.top().second;
 
        q.pop();
        if(visited[current]) continue;
        visited[current] = true;
 
        for(ii p : adj[current]){
            long weight = p.second;
            int to = p.first;
            if(visited[to]) continue;   
            if((dist[to] == -1 || dist[current] + weight < dist[to])){
                dist[to] = dist[current] + weight;
                q.push({dist[to], to});
            }
        }
    }
 
}
 
int main(){
 
    cin >> n >> m;
    adj.resize(n+1);
    dist.assign(n+1, INF);
    visited.assign(n+1, false);
 
    for(int j = 1 ; j <= m ; j++){
        int a, b;
        long w;
 
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    
    dijkstra();
 
    for(int i = 1 ; i < dist.size(); i++){
        cout << dist[i] << " ";
    }
    return 0;
}