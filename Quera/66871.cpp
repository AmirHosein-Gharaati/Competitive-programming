#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;


map<int, ii> mp1;
map<ii, int> mp2;
vector<int> primes;
vector<bool> isValid;
bool visited[110][110];
int board[110][110];
ii start, end_point;

vector<char> ans;
bool finished = false;

void build_and_check_primes(int maxx){
    bool flag;
    for(int i = primes.back()+1 ; i <= maxx ; i += 2){
        flag = true;
        for(int j = 0 ; j < primes.size() && (primes[j]*primes[j]) <= i ; j++){
            if(i%primes[j] == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            primes.push_back(i);
            isValid[i] = true;
        }
    }
}

void dfs(ii start){
    // cout << mp2[start] << endl;
    visited[start.first][start.second] = true;

    if(start.first == end_point.first && start.second == end_point.second){
        if(ans.empty()){
            return;
        }
        else if (!finished){
            finished = true;
            for(char c : ans){
                cout << c;
            }
            
            ans.pop_back();
        }
        
        return;
    }

    if(!visited[start.first+1][start.second] && isValid[mp2[{start.first+1, start.second}]]){
        ans.push_back('D');
        dfs({start.first+1, start.second});
        ans.pop_back();
    }

    if(!visited[start.first-1][start.second] && isValid[mp2[{start.first-1, start.second}]]){
        ans.push_back('U');
        dfs({start.first-1, start.second});
        ans.pop_back();
    }

    if(!visited[start.first][start.second+1] && isValid[mp2[{start.first, start.second+1}]]){
        ans.push_back('R');
        dfs({start.first, start.second+1});
        ans.pop_back();
    }

    if(!visited[start.first][start.second-1] && isValid[mp2[{start.first, start.second-1}]]){
        ans.push_back('L');
        dfs({start.first, start.second-1});
        ans.pop_back();
    }
}


int main(){
    isValid.assign(1000000010, false);
    primes.push_back(2);
    isValid[2] = true;

    int tt;
    cin >> tt;
    while(tt--){
        int maxx = -1;
        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));

        mp1.clear();
        mp2.clear();
        ans.clear();
        finished = false;
        int n;
        int number;
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cin >> number;
                maxx = max(maxx, number);
                board[i][j] = number;
                mp1[number] = {i, j};
                mp2[{i, j}] = number;
            }
        }
        build_and_check_primes(maxx);

        int a, b;
        cin >> a >> b;
        start = {a+1, b+1};
        cin >> a >> b;
        end_point = {a+1, b+1};

        dfs(start);
        if(!finished)
            cout << "No Monaseb Masir!";
        if(tt)
            cout << endl;
    }


    return 0;
}