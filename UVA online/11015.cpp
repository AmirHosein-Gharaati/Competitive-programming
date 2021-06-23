#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dist;
map<string, int> mp1;
map<int, string> mp2;
const int INF = 1e8;
int n, m;

void floyd_warshall(){

    for(int i = 1 ; i<= n ; i++) dist[i][i] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= n ; k++){
                dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
            }
        }
    }
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt = 0;
    while(cin >> n >> m && n+m != 0){
        tt++;
        int number = 1;
        mp1.clear();
        mp2.clear();

        dist.clear();
        dist = vector<vector<int>>(n+1, vector<int>(n+1, INF));

        for(int i = 0 ; i < n ; i++){
            string name;
            cin >> name;
            mp1[name] = number;
            mp2[number] = name;
            number++;
        }

        for(int i = 0 ; i < m ; i++){
            int a, b, c;
            cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }

        floyd_warshall();

        int minn = INF;
        int s;
        for(int i = 1 ; i <= n ; i++){
            int res = 0;
            for(int j = 1 ; j <= n ; j++){
                res += dist[i][j];
            }
            if(res < minn) {
                s = i;
                minn = res;
            }
        }

        cout << "Case #" << tt << " : " << mp2[s] << endl;
        
    }



    return 0;
}