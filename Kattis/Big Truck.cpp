#include <bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int, int>> iii;
typedef pair<int, int> ii;
int n, m;
vector<vector<ii>> adj;
vector<int> values, dist, best_items;
vector<bool> visited;
const int INF = 1e6;

void dijkstra(){

    priority_queue<iii, vector<iii>, greater<iii>> q;
    dist[1] = 0;
    q.push({0, {values[1], 1}});
    best_items = values;

    while(!q.empty()){

        int current = q.top().second.second;
        int curr_val = q.top().second.first;

        q.pop();

        visited[current] = true;

        for(auto next : adj[current]){
            int to = next.first;
            int cost = next.second;

            if(dist[current] + cost < dist[to]){
                dist[to] = dist[current] + cost;
                best_items[to] = best_items[current] + values[to];
                q.push({dist[to], {best_items[to], to}});
            }

            else if(dist[current] + cost == dist[to]){
                best_items[to] = max(best_items[current] + values[to], best_items[to]);
                q.push({dist[to], {best_items[to], to}});
            }
        }
        
    }

}

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    adj.resize(n+1);
    values.resize(n+1);
    dist.assign(n+1, INF);
    visited.assign(n+1, false);

    for(int i = 1 ; i <= n ; i++){
        cin >> values[i];
    }

    cin >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijkstra();

    if(!visited[n]){
        cout << "impossible";
    }
    else{
        cout << dist[n] << " " << best_items[n];
    }

    return 0;
}