#include <bits/stdc++.h>

using namespace std;
int n, W;
vector<int> weights, values;
vector<vector<int>> dp;

void knapsack(){

    dp = vector<vector<int>>(n+1, vector<int>(W+1));

    for(int i  = 0 ; i <= n ; i++){
        for(int w = 0 ; w <= W ; w++){

            if(i == 0 || w == 0)
                dp[i][w] = 0;
            
            else if(weights[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> W;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        weights.push_back(a);
    }
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        values.push_back(a);
    }

    knapsack();

    cout << dp[n][W];
    // for(int i = 0 ; i <= n ; i++){
    //     for(int j = 0 ; j <= W ; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}