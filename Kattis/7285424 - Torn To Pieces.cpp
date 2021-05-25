#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
map<int, string> mp1;
map<string, int> mp2;
vector<int> p;


void bfs(string source, string dest){
    int s = mp2[source];
    int d = mp2[dest];

    if(s == 0 || d == 0){
        cout << "no route found";
        return ;
    }

    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    p[s] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                p[u] = v;
            }
        }
    }

    if(!visited[d]){
        cout << "no route found";
    }
    else{
        vector<int> path;
        for(int i = d ; i != -1 ; i = p[i]){
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for(int s : path){
            cout << mp1[s] << " ";
        }
    }
}


int main(){

    cin >> n;
    adj.resize(n*n+1);
    visited.assign(n*n+1, false);
    p.resize(n*n+1);
    p.assign(n*n+1, -1);

    stringstream sin;
    string line, temp;
    cin.ignore(1000, '\n');
    int number = 1;

    for(int i = 0 ; i < n ;i++){
        string first;
        getline(cin, line);
        sin.clear();
        sin << line;

        sin >> first;
        if(mp2.find(first) == mp2.end()){
            mp1[number] = first;
            mp2[first] = number;
            number++;
        }

        int ind = mp2[first];


        while(sin >> temp){

            if(mp2.find(temp) == mp2.end()){
                mp1[number] = temp;
                mp2[temp] = number;
                number++;
            }
            int ind2 = mp2[temp];

            if(find(adj[ind].begin(), adj[ind].end(), ind2) == adj[ind].end())
                adj[ind].push_back(ind2);
            
            if(find(adj[ind2].begin(), adj[ind2].end(), ind) == adj[ind2].end())
                adj[ind2].push_back(ind);

        }
    }

    string source, dest;
    cin >> source >> dest;

    bfs(source, dest);


    return 0;
}