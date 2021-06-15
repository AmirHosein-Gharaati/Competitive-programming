#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> dp;

const ll mod = 1e9 + 7;

signed main(){

    int n;
    cin >> n;
    dp = vector<ll>(n+1, 0);
    dp[0] = 1;

    for(int i = 1 ; i <= n ; i++){

        for(int j = 1 ; j <= 6 ; j++){

            if(i-j >= 0){
                dp[i] += dp[i-j];
                dp[i] = (dp[i]%mod);
            }
        }
        
    }

    cout << dp[n];


    return 0;
}