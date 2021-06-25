#include <bits/stdc++.h>

using namespace std;
vector<int> times, ans1, ans2;
vector<vector<int>> dp;

int t, n;

void knapsack(int w){
    dp = vector<vector<int>>(n+1, vector<int>(w+1));

    for(int i = 0 ; i <= n ; i++){
        for(int weight = 0 ; weight <= w ; weight++){
            if(i == 0 || weight == 0)
                dp[i][weight] = 0;

            else if(times[i-1] <= weight){
                dp[i][weight] = max(dp[i-1][weight], times[i-1] + dp[i-1][weight - times[i-1]]);
            }
            else{
                dp[i][weight] = dp[i-1][weight];
            }
        }
    }

    int temp = w;
    int res = dp[n][w];
    for(int i = n ; i > 0 && res > 0 ; i--){
        if(dp[i][temp] != dp[i-1][temp]){
            ans1.push_back(i-1);
            res -= times[i-1];
            temp -= times[i-1];
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> n;

    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        times.push_back(a);
    }


    knapsack(t);

    int t1 = 0, t2 = 0;
    for(int i = 0 ; i < n; i++){
        auto it = find(ans1.begin(), ans1.end(), i);

        if(it != ans1.end()){
            cout << t1 << " ";
            t1 += times[i];
        }
        else{
            cout << t2 << " ";
            t2 += times[i];
        }
    }

    return 0;
}