#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> edge;
vector<edge> edges;
int n, m;
int minimum_cost = 0;
vector<int> id;

void initialize(){
    id.resize(m);
    for(int i = 0 ; i < m ; i++){
        id[i] = i;
    }
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

void kruskal(){
    int x, y, cost;
    for(int i = 0 ; i < m ; i++){
        x = edges[i].second.first;
        y = edges[i].second.second;
        cost = edges[i].first;

        if(root(x) != root(y)){
            minimum_cost += cost;
            union1(x, y);
        } 
    }
}


int main(){

    cin >> n >> m;
    initialize();
    for(int i = 0 ; i < m ; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        edges.push_back(make_pair(weight, make_pair(a, b)));
    }

    sort(edges.begin(), edges.end());
    kruskal();

    cout << minimum_cost ;


    return 0;
}