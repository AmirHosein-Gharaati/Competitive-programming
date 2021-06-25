#include <bits/stdc++.h>

using namespace std;

typedef struct island{
    int x, y, r;
} island;
typedef pair<int, double> id;
typedef pair<double, int> di;

double dist(island &a, island  &b){
    return (sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2)) - a.r - b.r);
}

const double INF = 1e8;

void dijkstra(vector<vector<id>>& adj,vector<double>& distt, int& n, int& k, int& m, vector<bool>& visited){

    distt.assign(110, INF);
    distt[0]= 0;
    priority_queue<di, vector<di>, greater<di>> q;
    q.push({0.0, 0});

    
    while(!q.empty()){
        int current = q.top().second;
        q.pop();
        // cout << current << endl;

        if(visited[current]) continue;
        visited[current] = true;    

        for(auto next : adj[current]){
            int to = next.first;
            double weight = next.second;
            // cout << to << " " << weight << endl;

            if(distt[current] + weight < distt[to]){
                distt[to] = distt[current] + weight;
                q.push({distt[to], to});
            }
        }
        
    }
    
}

int main(){


    int k, m;
    while(scanf("%d %d", &k, &m) != EOF){
        vector<island> islands(2);
        cin >> islands[0].x >> islands[0].y >> islands[0].r;
        cin >> islands[1].x >> islands[1].y >> islands[1].r;
        
        int n;
        cin >> n;
        for(int i = 0; i < n ; i++){
            island tmp;
            cin >> tmp.x >> tmp.y >> tmp.r;
            islands.push_back(tmp);
        }

        vector<vector<id>> adj(110);

        for(int i = 0 ; i < n+2 ; i++){
            for(int j = i+1 ; j < n+2 ; j++){
                double d = dist(islands[i], islands[j]);
                if(d <= k*m){
                    // cout << i << " " << j << " " << d << endl; 
                    adj[i].push_back({j, d});
                    adj[j].push_back({i, d});
                }
            }
        }
        vector<double> distt;
        vector<bool> visited(110, false);
        

        dijkstra(adj, distt, n, k, m, visited);

        if(distt[1] != INF){
            cout << "Larry and Ryan will escape!" << endl;
        }
        else{
            cout << "Larry and Ryan will be eaten to death." << endl;
        }
    }

    return 0;
}