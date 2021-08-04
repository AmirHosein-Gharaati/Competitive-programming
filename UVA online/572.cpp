#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board;
vector<vector<bool>> visited;
int m, n;

void dfs(int x, int y){

    visited[x][y] = true;
    // cout << x << " " << y << endl;

    for(int i = -1 ; i <= 1 ; i++){
        for(int j = -1 ; j <= 1 ; j++){
            int new_i = x+i;
            int new_j = y+j;

            if(new_i >=0 && new_i < m && new_j >= 0 && new_j < n && board[new_i][new_j] == '@'){
                if(!visited[new_i][new_j])
                    dfs(new_i, new_j);
            }
        }
    }

}

int main(){

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    while(scanf("%d %d", &m, &n) && m + n != 0){

        board = vector<vector<char>>(m+1, vector<char>(n+1, ' '));
        visited = vector<vector<bool>>(m+1, vector<bool>(n+1, false));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> board[i][j];
            }
        }

        int counter = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == '@' && !visited[i][j]){
                    // cout << i << " " << j << endl;
                    counter++;
                    dfs(i, j);
                }
            }
        }

        // cout << visited[1][1] <<endl;;

        cout << counter << endl;
    }





    return 0;
}