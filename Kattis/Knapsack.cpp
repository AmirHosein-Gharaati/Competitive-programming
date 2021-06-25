#include <bits/stdc++.h>

using namespace std;
vector<int> weights, values;
vector<vector<int>> dp;
vector<int> indexes;
int main(){

    int n, w;

    while(scanf("%d %d", &w, &n) != EOF){
        weights.clear();
        values.clear();

        for(int i = 0 ; i < n ; i++){
            int a, b;
            cin >> a >> b;
            values.push_back(a);
            weights.push_back(b);
        }

        dp.clear();
        dp = vector<vector<int>>(n+1, vector<int>(w+1));

        for(int i = 0 ; i<= n ; i++){
            for(int k = 0 ; k <= w ; k++){

                if(i == 0 || k == 0){
                    dp[i][k] = 0;
                }

                else if(weights[i-1] <= k){
                    dp[i][k] = max(dp[i-1][k], values[i-1] + dp[i-1][k - weights[i-1]]);
                }
                else
                    dp[i][k] = dp[i-1][k];
            }
        }

        int temp = w;
        
        indexes.clear();

        for(int i = n ; i > 0 ; i--){
            if(dp[i][temp] != dp[i-1][temp]){
                indexes.push_back(i-1);
                temp -= weights[i-1];
            }
        }
        cout << indexes.size() << endl;
        for(int next = 0 ; next < indexes.size(); next++){
            cout << indexes[next] << " " ;
        }
        cout << endl;
    }


    return 0;
}