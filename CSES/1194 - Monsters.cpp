#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;

vector<ii> monsters;
ii start;
ii end_point;
vector<vector<int>> dist, visited;
vector<vector<ii>> parent;
vector<char> path;
bool isDone = false;
char board[1010][1010];
int h, w;
const int INF = 1 << 30;
ii coords[] = {
    {1, 0},{0, 1},{-1, 0},{0, -1}
};


void bfs(){

    priority_queue<iii, vector<iii>, greater<iii>> q;
    for(ii p : monsters){
        int x = p.first;
        int y = p.second;

        q.push({0, {x, y}});
        dist[x][y] = 0;
        // cout << dist[x][y] << " " << x << " " << y << endl;
    }


    parent = vector<vector<ii>>(1010, vector<ii>(1010, {-1, -1}));
    

    while(!q.empty()){
        int x = q.top().second.first;
        int y = q.top().second.second;

        q.pop();
        
        // cout << x << " " << y << endl;
        for(ii cor : coords){
            int xx = x+cor.first;
            int yy = y+cor.second;

            if(xx >= 1 && xx <= h && yy >= 1 && yy <= w && board[xx][yy] != '#'){
                if(dist[x][y] + 1 < dist[xx][yy]){
                    dist[xx][yy] = dist[x][y] + 1;
                    q.push({dist[xx][yy], {xx, yy}});
                }
            }
        }
    }

    queue<iii> qq;
    qq.push({0, {start.first, start.second}});
    parent[start.first][start.second] = {-1, -1};

    while(!qq.empty()){
        int current_len = qq.front().first;
        int x = qq.front().second.first;
        int y = qq.front().second.second;
        // cout << current_len << " " << x << " " << y << endl;
        visited[x][y] = 1;

        if(x == 1 || x == h || y == 1 || y == w){
            isDone = true;
            end_point = {x, y};
            break;
        };


        qq.pop();

        for(ii cor : coords){
            int xx = x+cor.first;
            int yy = y+cor.second;

            if(xx >= 1 && xx <= h && yy >= 1 && yy <= w && board[xx][yy] != '#'){
                if(dist[xx][yy] > current_len+1 && !visited[xx][yy]){
                    parent[xx][yy] = make_pair(x, y);
                    qq.push({current_len+1, {xx, yy}});
                    visited[xx][yy] = 1;
                }
            }
        }
    }

}


int main(){

    cin >> h >> w;
    dist = vector<vector<int>>(1010, vector<int>(1010, INF));
    visited = vector<vector<int>>(1010, vector<int>(1010, 0));
    memset(board, '.', sizeof(board));

    char c;
    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= w ; j++){
            cin >> c;
            if(c == 'M') monsters.push_back({i, j});
            else if(c == 'A') start = {i, j};
            board[i][j] = c;
        }
    }

    bfs();

    if(isDone){
        cout << "YES" << endl;
        ii t;
        for( t = end_point ; t.first != -1 || t.second != -1 ; ){
            int x = t.first;
            int y = t.second;

            // cout << x << " " << y << endl;

            int px = parent[x][y].first;
            int py = parent[x][y].second;

            if(y - py == 1) path.push_back('R');
            else if(y - py == -1) path.push_back('L');
            else if(x - px == 1) path.push_back('D');
            else if(x - px == -1) path.push_back('U');

            t.first = px;
            t.second = py;
        }
        // path.pop_back();
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for(char c : path) cout << c;
    }
    else{
        cout << "NO";
    }

    return 0;
}