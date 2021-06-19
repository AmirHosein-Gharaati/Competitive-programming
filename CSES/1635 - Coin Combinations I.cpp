#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
const int mod = 1e9 + 7;

vector<int> coins;
vector<int> dp;

int solve(int u){

    if(dp[u] == 0) return 0;
    if(dp[u] != -1) return dp[u];

    int result = 0;

    for(int coin : coins){
        if(u - coin >= 0){
            result = result + ((solve(u - coin))% mod);
        }
    }

    dp[u] = result%mod;
    return result;

}

signed main(){
    fast;

    int n, x;
    cin >> n >> x;


    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        coins.push_back(a);
    }
    

    dp.assign(x+1, -1);
    dp[0] = 1;

    solve(x);

    cout << dp[x]%mod;

    return 0;
}