#include <bits/stdc++.h>

using namespace std;

int width, height;

typedef vector<vector<int>> vvi;
vector<vector<char>> board;

void bfs(int vert, int hor, vvi& dp){
    dp.clear();
    dp.resize(height+2);
    for(int i = 0 ; i < dp.size(); i++){
        dp[i].assign(width+2, -1);
    }

    pair<int, int> coords[] = {{0, 1},{1, 0},{0, -1},{-1, 0}};

    queue<pair<int, int>> q[] = {
        queue<pair<int, int>>(),
        queue<pair<int, int>>()
    };

    q[0].push(make_pair(vert, hor));
    int current_q = 0;
    int currentMin = 0;
    dp[vert][hor] = 0;
    while(!q[0].empty() || !q[1].empty()){
        if(q[current_q].empty()){
            currentMin++;
            current_q ^= 1;
        }
        
        pair<int, int> temp = q[current_q].front();
        q[current_q].pop();

        for(pair<int, int> p : coords){
            pair<int ,int> newCor = make_pair( temp.first+p.first, temp.second+p.second);
            // cout << newCor.first << " " << newCor.second << " " << board[newCor.first][newCor.second] << endl;

            if(newCor.first >= 0 && newCor.first <= height+1 && newCor.second >= 0 && newCor.second <= width+1 && board[newCor.first][newCor.second] != '*' && dp[newCor.first][newCor.second] == -1){
                dp[newCor.first][newCor.second] = currentMin;
                if(board[newCor.first][newCor.second] == '#')
                    q[current_q^1].push(make_pair(newCor.first, newCor.second));
                else
                    q[current_q].push(make_pair(newCor.first, newCor.second));
            }
        }
    }
}


int main(){

    int tt;
    cin >> tt;
    vvi bfs1, bfs2, bfs3;
    while(tt--){
        cin >> height >> width;

        board.clear();
        board.resize(height+2);
        for(int i = 0 ; i < board.size(); i++){
            board[i].assign(width+2, '.');
        }

        vector<pair<int, int>> sources;
        sources.clear();
        sources.push_back(make_pair(0, 0));

        char c;
        for(int i = 1 ; i <= height; i++){
            for(int j = 1 ; j <= width; j++){
                cin >> c;
                board[i][j] = c;
                if(c == '$'){
                    sources.push_back(make_pair(i, j));
                }
            }
        }

        bfs(sources[0].first, sources[0].second, bfs1);
        bfs(sources[1].first, sources[1].second, bfs2);
        bfs(sources[2].first, sources[2].second, bfs3);

        int result = INT_MAX;
        for(int i = 0 ; i <= height+1; i++){
            for(int j = 0 ; j <= width+1; j++){
                if(bfs1[i][j] >= 0 && bfs2[i][j] >= 0 && bfs3[i][j] >= 0){
                    int cost = bfs1[i][j] + bfs2[i][j] + bfs3[i][j];
                    if(board[i][j] == '#') cost++;
                    result = min(result, cost);
                }
            }
        }

        cout << result << endl;
    }


    return 0;
}