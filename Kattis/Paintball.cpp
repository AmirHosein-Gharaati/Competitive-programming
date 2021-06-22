#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<int> mt;
vector<bool> used;
int n, m;

bool try_kuhn(int u){
    if(used[u])
        return false;

    used[u] = true;

    for(int to : adj[u]){
        if(used[to]) continue;
        if(mt[to] == -1 || try_kuhn(mt[to])){
            mt[to] = u;
            mt[u] = to;
            return true;
        }
    }

    return false;
}


bool solve(){

    mt.assign((n+1)*2, -1);

    int counter = 0;
    for(int i = 1 ; i <= n ; i++){
        used.assign((n+1)*2, false);
        if(try_kuhn(i)) counter++; 
    }

    return counter == n;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    adj.resize((n+1)*2);

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b+n);
        adj[b+n].push_back(a);

        adj[b].push_back(a+n);
        adj[a+n].push_back(b);
    }


    if(solve()){
        for(int i = 1 ; i <= n ; i++){
            cout << mt[i]-n << endl;
        }
    }

    else{
        cout << "Impossible";
    }

    return 0;
}