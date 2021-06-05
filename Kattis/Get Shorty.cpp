#include <bits/stdc++.h>

using namespace std;
typedef pair<double, int> di;
typedef pair<int, double> edge;
int n, m;
vector<vector<edge>> adj;
vector<double> dist;
vector<int> parent;
vector<bool> visited;
double maxii;

bool all_visited(int x){
    for(int i = 0 ; i < adj[x].size() ; i++){
        if(!visited[adj[x][i].first]){
            return false;
        }
    }
    return true;
}

void dijkstra(){

    priority_queue<di> q;
    q.push({1.0, 0});
    dist = vector<double>(n+1, 0.0);
    parent = vector<int>(n+1, -1);
    visited = vector<bool>(n+1, false);
    dist[0] = 1.0;
    maxii = 0.0;

    while(!q.empty()){
        int x = q.top().second;
        double weight = q.top().first;
        q.pop();
        visited[x] = true;

        if(all_visited(x)){
            continue;
        }

        // cout << x << " " << weight << endl;

        for(int i = 0 ; i < adj[x].size(); i++){
            int to = adj[x][i].first;
            double len = adj[x][i].second;

            if(dist[x] * len > dist[to]){
                parent[to] = x;
                dist[to] = dist[x]*len;
                q.push({dist[to], to});
            }
        }
    }

}


int main(){

    while(cin >> n >> m && n+m != 0){
        adj.clear();
        adj.resize(n+1);

        for(int i = 0 ;i < m ; i++){
            int a, b;
            double weight;
            cin >> a >> b >> weight;
            adj[a].push_back(edge(b, weight));
            adj[b].push_back(edge(a, weight));
        }

        dijkstra();
        printf("%.4lf\n", dist[n-1]);
    }



    return 0;
}