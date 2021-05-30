#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
typedef pair<int, pair<int, int>> edge;
typedef pair<int ,int> ii;
int n ,m;
vector<edge> edges;
vector<ii> ans;
int minimum_cost ;
vector<bool> visited;

void init(){
    parent.clear();
    parent.resize(n);
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
    }
}

int root(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void union1(int x, int y){
    int p = root(x);
    int q = root(y);
    parent[p] = parent[q];
}

void kruskal(){
    int x, y, cost;
    for(int i = 0 ; i < m ; i++){
        x = edges[i].second.first;
        y = edges[i].second.second;
        cost = edges[i].first;

        if(root(x) != root(y)){
            visited[x] = true;
            visited[y] = true;
            minimum_cost += cost;
            union1(x, y);
            ans.push_back(make_pair(x, y));
        } 
    }
}

int main(){

    while(cin >> n >> m && n+m != 0){
        init();
        adj.clear();
        adj.resize(n);
        ans.clear();
        visited.clear(); visited.assign(n, false);
        
        edges.clear();

        for(int i = 0 ; i < m ; i++){
            int source, dest, weight;
            cin >> source >> dest >> weight;

            edges.push_back(make_pair(weight, make_pair(source, dest)));
        }

        sort(edges.begin(), edges.end());
        minimum_cost= 0;
        kruskal();
        
        bool flag = true;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                flag = false;
                break;
            }
        }

        if(flag){
            cout << minimum_cost << endl;
            
            for(int i = 0 ;i < ans.size(); i++){
                if(ans[i].first >= ans[i].second){
                    int temp = ans[i].first;
                    ans[i].first = ans[i].second;
                    ans[i].second = temp;
                }
            }

            sort(ans.begin(), ans.end());
            for(ii p : ans){
                cout << p.first << " " << p.second << endl;
            }
        }
        else{
            cout << "Impossible" << endl;
        }
    }



    return 0;
}