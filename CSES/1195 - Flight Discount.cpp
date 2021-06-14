#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
int n, m;
vector<vector<ii>> adj;
vector<int> dist;
vector<bool> visited;

const int INF = 1e15;

void dijkstra(){

    priority_queue<iii, vector<iii>, greater<iii>> q;
    dist[1] = 0;
    // distance, {current, max_edge}
    q.push({0, {1, 0}});

    while(!q.empty()){

        int curr_dist = q.top().first;
        int current = q.top().second.first;
        int max_edge = q.top().second.second;
        // cout << current << " " << curr_dist << " " << max_edge << endl;
        q.pop();

        if(current == n){
            if(dist[n] > (curr_dist-(max_edge - floor(max_edge/2)))){
                dist[n] = (curr_dist-(max_edge - floor(max_edge/2)));
            }
            continue;
        }

        if(visited[current]) continue;
        visited[current] = true ;


        for(auto edge : adj[current]){

            int next = edge.first;
            int weight = edge.second;   
            int new_dist, new_max;

            new_dist = curr_dist + weight;
            new_max = max(weight, max_edge);
            // if(max_edge < weight){
            //     new_dist = curr_dist + (max_edge-(floor(max_edge/2)));
            //     new_dist += floor(weight/2);
            //     new_max = weight;
            // }
            // else{
            //     new_dist = curr_dist + weight;
            //     new_max = max_edge;
            // }
            if(!visited[next] && (next == n || new_dist < dist[next])){
                if(next != n){
                    dist[next] = new_dist;
                }
                q.push({new_dist, {next, new_max}});
                // cout << next << " " << new_dist << " " << new_max << endl;

            }
        }
        
    }
    
}

signed main(){

    cin >> n >> m;
    dist.assign(n+1, INF);
    adj.resize(n+1);
    visited.assign(n+1, false);

    for(int i = 0 ; i < m ; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    dijkstra();

    cout << dist[n];


    return 0;
}