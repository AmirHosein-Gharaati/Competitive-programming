#include <bits/stdc++.h>

using namespace std;

int h, w;
int board[30][70];
int inf = 1 << 30;

typedef pair<int, int> ii;
typedef pair<int ,pair<int, int>> iii;
bool isDone[30][70];
ii parent[30][70];

void dijkstra(){
    
    for(int i = 0 ; i < 25 ; i++){
        for(int j = 0 ; j < 65 ; j++){
            parent[i][j] = {-1, -1};
        }
    }
    
    memset(isDone, false, sizeof(isDone));
    vector<vector<int>> dist(h+2, vector<int>(w,inf));
    dist[0][0] = 0;

    priority_queue<iii> q;
    q.push({0, {0, 0}});

    ii coords[] = {
        {1, 0},{-1, 0},{1, 1},{1, -1},
        {0, 1},{0, -1},{-1 ,-1},{-1, 1},
    };

    while(!q.empty()){
        int x = q.top().second.first;
        int y = q.top().second.second;

        q.pop();
        // cout << x << " " << y << endl;
        isDone[x][y] = true;

        for(ii p : coords){
            int i = p.first + x;
            int j = p.second + y;

            if(i>=0 && i <= h+1 && j >= 0 && j < w){
                if(!isDone[i][j] && (dist[x][y] + board[i][j] < dist[i][j])){
                    
                    parent[i][j] = {x, y};
                    dist[i][j] = dist[x][y] + board[i][j];
                    q.push({-dist[i][j], {i, j}});
                }
            }
        }
    }

}

int main(){


    while(scanf("%d %d", &h, &w) && h+w != 0){
        memset(board, 0, sizeof(board));

        char c;
        for(int i = 1 ; i <= h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin >> c;
                board[i][j] = c - '0';
            }
        }

        dijkstra();

        int x = h+1;
        int y = w-1;

        while(1){
            int temp1 = x;
            int temp2 = y;

            if(temp1 == -1 || temp2 == -1) break;
            board[x][y] = ' ' - '0' ;

            x = parent[temp1][temp2].first;
            y = parent[temp1][temp2].second;
            
        }

        for(int i = 1 ; i <= h ; i++){
            for(int j = 0 ; j < w ; j++){
                cout << char(board[i][j] + '0');
            }
            cout << endl;
        }
        cout << endl;
    }



    return 0;
}