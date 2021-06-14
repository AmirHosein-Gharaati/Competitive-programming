#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<vector<int>> d;
const int INF = 1e15;

int n, m, q;

void floyd_warshall(){  
    for(int i=1 ; i<=n ;i++ ) d[i][i] = 0;
 
    for(int i=1 ; i<=n ;i++ )
        for(int j=1; j<=n ; j++ )
            for(int k=1; k<=n ; k++ ){
                if(d[j][i] + d[i][k] < d[j][k]){
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
    return ;
}

signed main(){

    cin >> n >> m >> q;
    
    d= vector<vector<int>>(n+1, vector<int>(n+1, INF));

    for(int i = 0 ; i < m ;i++){
        int a, b;
        int w;
        cin >> a >> b >> w;

        d[a][b] = min(d[a][b], w);
        d[b][a] = min(d[b][a], w);
    }   

    floyd_warshall();

    for(int i = 0 ; i < q ; i++){
        int a, b;
        cin >> a >> b;
        
        if(d[a][b] != INF) cout << d[a][b] << endl; 
        else cout << -1 << endl;
            
    }


    return 0;
}