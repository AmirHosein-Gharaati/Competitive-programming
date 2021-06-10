#include <bits/stdc++.h>

using namespace std;

char board[1010][1010];
int h, w;
bool visited[1010][1010];

pair<int ,int> coords[] = {
    {1, 0},{0, 1},{-1, 0},{0, -1}
};

void dfs(int i, int j){

    visited[i][j] = true;

    for(pair<int, int> p : coords){
        int ii = i + p.first;
        int jj = j + p.second;

        if(ii >=0 && ii < h && jj >= 0 && jj < w && board[ii][jj] == '.' && !visited[ii][jj]){
            dfs(ii, jj);
        }
    }
}


int main(){

    cin >> h >> w;

    memset(visited, false, sizeof(visited));

    int counter = 0;
    for(int i = 0 ;i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            if(board[i][j] == '.' && !visited[i][j]){
                counter++;
                dfs(i, j);
            }
        }
    }

    cout << counter;
    return 0;
}