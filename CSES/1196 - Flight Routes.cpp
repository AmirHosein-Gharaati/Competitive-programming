#include <bits/stdc++.h>


using namespace std;
#define ll long long

typedef pair<int, ll> il;
typedef pair<ll, int> li;

vector<vector<il>> adj;
vector<int> visited;
int n, m, k;

void dijkstra(){

    priority_queue<li, vector<li>, greater<li>> q;
    q.push({0, 1});
    int counter = 0;

    while(!q.empty()){
        int current = q.top().second;
        ll weight = q.top().first;

        q.pop();
        
        visited[current]++;
        if(visited[current] > k) continue;
        
        if(current == n){
            counter++;
            cout << weight << " ";
            if(counter == k) return;
        }

        for(auto p : adj[current]){
            int to = p.first;
            int w = p.second;

            if(visited[to] < k)
                q.push({w+weight, to});
        }
    }


}


int main(){


    cin >> n >> m >> k;
    adj.resize(n+1);
    visited.assign(n+1, 0);
    for(int i = 0 ; i < m ; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }


    dijkstra();

    

    return 0;
}