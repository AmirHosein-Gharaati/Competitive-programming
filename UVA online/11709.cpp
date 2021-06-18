#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order;

map <int, string> mp1;
map<string, int> mp2;


void dfs(int u){

    visited[u] = true;

    for(int next : adj[u]){
        if(!visited[next]){
            dfs(next);
        }
    }

    order.push_back(u);
}


void dfs2(int u){


    visited[u] = true;

    for(int next : adj_rev[u]){
        if(!visited[next]){
            dfs2(next);
        }
    }
}

int main(){

    int n, m;
    while(scanf("%d %d", &n ,&m) && n + m != 0){
        adj.clear();
        adj.resize(n+1);

        adj_rev.clear();
        adj_rev.resize(n+1);

        visited.clear();
        visited.assign(n+1, false);

        mp1.clear();
        mp2.clear();

        int number = 1;
        for(int i = 0 ; i < n ; i++){

            string first, second;
            cin >> first >> second;
            string name;
            name = first + " " + second;

            mp1[number] = name;
            mp2[name] = number;
            number++;
        }

        for(int i = 1 ; i <= m ; i++){
            string first, second;
            string first2, second2;
            cin >> first >> second;
            cin >> first2 >> second2;
            string name1, name2;
            name1 = first + " " +  second;
            name2 = first2 + " " +  second2;

            int a, b;
            a = mp2[name1];
            b = mp2[name2];

            adj[a].push_back(b);
            adj_rev[b].push_back(a);
        }

        

        order.clear();
        for(int i = 1 ; i <= n ;i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        visited.assign(n+1, false);
        reverse(order.begin(), order.end());

        int counter = 0;
        for(int i : order){
            if(!visited[i]){
                counter++;
                dfs2(i);
            }
        }

        cout << counter << endl;

    }



    return 0;
}