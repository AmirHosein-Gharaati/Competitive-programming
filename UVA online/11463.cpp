#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj, dist;
int n;
const int INF = 1e4;

void floyd_warshall(){
    for(int i = 0 ; i < n ; i++) dist[i][i] = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
            }
        }
    }
    
}

int main(){

    int tt;
    scanf("%d", &tt);
    for(int t = 1 ; t <= tt ; t++){
        int m;
        scanf("%d %d", &n, &m);
        adj.clear();
        adj.resize(n+1);

        dist.clear();
        dist = vector<vector<int>>((n+1), vector<int>(n+1, INF));

        for(int i = 0 ; i < m ; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            dist[a][b] = 1;
            dist[b][a] = 1;

        }
        int s, p;
        scanf("%d %d", &s, &p);

        floyd_warshall();

        int minn = 0;
        for(int i = 0 ; i < n ; i++){
            if(dist[s][i] != INF && dist[i][p] != INF){
                minn = max(minn, dist[s][i]+dist[i][p]);
            }
            
        }

        printf("Case %d: %d\n", t, minn);
    }


    return 0;
}