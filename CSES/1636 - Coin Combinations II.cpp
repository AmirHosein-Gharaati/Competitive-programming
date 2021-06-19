#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9+7;
const int inf = 1e15;
vector<int> dp, coins;
int n, x;


signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    cin >> n >> x;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        coins.push_back(a);
    }

    dp.assign(x+1, 0);
    dp[0] = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j-coins[i] >= 0)
            {
            dp[j] += dp[j-coins[i]];
            dp[j] %= mod;
            }
        }
    }

    cout << dp[x] << endl;
    return 0;
}