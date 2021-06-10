#include <bits/stdc++.h>

using namespace std;
typedef pair<int ,int> ii;

int h, w;
char board[1010][1010];
bool visited[1010][1010];
ii parent[1010][1010];
bool done = false;
vector<ii> path_num;
vector<char> path;
ii start, endd;
ii coords[] = {
    {1, 0},{0, 1},{-1, 0},{0, -1}
};



void bfs(){

    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++)
            parent[i][j] = {-1, -1};
    }

    queue<ii> q;
    q.push(start);

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;

        visited[i][j] = true;
        q.pop();

        for(ii p : coords){
            int ii = i + p.first;
            int jj = j + p.second;

            if(ii >= 0 && ii < h && jj >= 0 && jj < w && board[ii][jj] != '#' && !visited[ii][jj]){
                parent[ii][jj] = {i, j};
                visited[ii][jj] = true;
                q.push({ii, jj});
                if(board[ii][jj] == 'B'){
                    done = true;
                    break;
                }
            }
        }
    }

    for(ii p = endd ; p.first != -1 && p.second != -1 ; p = parent[p.first][p.second]){
        path_num.push_back(p);
    }

    reverse(path_num.begin(), path_num.end());

    for(int i = 0 ; i < path_num.size()-1 ; i++){
        int i1 = path_num[i].first;
        int j1 = path_num[i].second;

        int i2 = path_num[i+1].first;
        int j2 = path_num[i+1].second;

        if(i1 - i2 == -1) path.push_back('D');
        else if(i1 - i2 == 1) path.push_back('U');
        else if(j1 - j2 == -1) path.push_back('R');
        else if(j1 - j2 == 1) path.push_back('L');
    }
}

int main(){

    cin >> h >> w;

    char c;
    for(int i = 0 ; i < h ; i++)
        for(int j = 0 ; j < w ; j++){
            cin >> c;
            if(c == 'A')
                start = make_pair(i, j);
            
            else if(c == 'B')
                endd = make_pair(i, j);
            
            board[i][j] = c;

        }
            
    bfs();
    
    if(done){
        cout << "YES" << endl << path.size() << endl;
        for(char c : path) cout << c;
    }
    else{
        cout << "NO";
    }


    return 0;
}