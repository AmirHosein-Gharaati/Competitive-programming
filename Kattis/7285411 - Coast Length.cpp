#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
vector<vector<int>> adj;
vector<bool> visited;
map<int, ii> mp1;
map<ii, int> mp2;
int board[1010][1010];
int counter = 0;
int n, m;



void dfs(int num){
    visited[num] = true;
    ii index = mp1[num];

    if(index.first != 0 && board[index.first-1][index.second] == 1){
        counter++;
    }
        

    if(index.first != n+1 && board[index.first+1][index.second] == 1){
        counter++;
    }

    if(index.second != 0 && board[index.first][index.second-1] == 1){
        counter++;
    }

    if(index.second != m+1 && board[index.first][index.second+1] == 1){
        counter++;
    }


    for(int u : adj[num]){
        if(!visited[u])
            dfs(u);
    }
        
    
}



int main(){

    memset(board, 0, sizeof(board));
    adj.resize(1020100);
    visited.assign(1020100, false);

    cin >> n >> m;

    char c;
    for(int i = 1 ; i <= n ;i++){
        for(int j = 1 ; j <= m; j++){
            cin >> c;
            c -= '0';
            board[i][j] = c;
        }
    }

    // for(int i = 0 ; i <= n+1 ;i++){
    //     for(int j = 0 ; j <= m+1; j++){
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }

    int number = 0;
    
    for(int i = 0 ; i <= n+1 ;i++){
        for(int j = 0 ; j <= m+1; j++){
            ii temp = {i, j};
            mp1[number] = temp;
            mp2[temp] = number;
            number++;
        }
    }

    for(int i = 0 ; i <= n+1 ; i++){
        for(int j = 0 ; j <= m+1 ; j++){
            
            if(board[i][j] == 0){
                ii temp = {i, j};
                int num = mp2[temp];

                if(i != 0 && board[i-1][j] == 0){
                    adj[num].push_back(mp2[{i-1, j}]);
                }
                
                if(i != n+1 && board[i+1][j] == 0){
                    adj[num].push_back(mp2[{i+1, j}]);
                }

                if(j != 0 && board[i][j-1] == 0){
                    adj[num].push_back(mp2[{i, j-1}]);
                }

                if(j != m+1 && board[i][j+1] == 0){
                    adj[num].push_back(mp2[{i, j+1}]);
                }
            }
        }
    }

    dfs(0);

    cout << counter;


    return 0;
}