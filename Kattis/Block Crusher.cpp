#include <bits/stdc++.h>

using namespace std;

int board[30][70];
int w, h;
int minimum_cost;
typedef pair<int, int> ii;
vector<ii> ans;
ii coords[] = {
    {0, -1},{1, -1}, {1, 0}, {1, 1},{0, 1}
};
vector<ii> current_path;

void dfs(int i, int j, int cost){
    
    if(i == h){
        if(cost < minimum_cost){
            ans.clear();
            ans = current_path;
            minimum_cost = cost;
        }
        return;
    }

    cost += board[i][j];
    if(cost > minimum_cost) return;


    for(ii p : coords){
        int new_i = i+p.first;
        int new_j = j+p.second;
        if(new_i <= h && new_j >= 0 && new_j < w){
            current_path.push_back(make_pair(new_i, new_j));
            dfs(new_i, new_j, cost);
            current_path.pop_back();
        }
    }

}

int main(){

    
    while(cin >> h >> w && w+h != 0){
        memset(board, 0, sizeof(board));
        minimum_cost = 1000;
        ans.clear();
        char c;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin >> c;
                board[i][j] = c - '0';
            }
        }

        current_path.clear();
        for(int i = 0 ; i < w ; i++){
            current_path.push_back(make_pair(0, i));
            dfs(0, i, 0);
            current_path.pop_back();
        }

        for(ii p : ans){
            board[p.first][p.second] = -1;
        }

        for(int i = 0 ; i < h; i++){
            for(int j = 0 ; j < w ; j++){
                if(board[i][j] == -1){
                    cout << " ";
                }
                else{
                    cout << board[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;

    }



    return 0;
}