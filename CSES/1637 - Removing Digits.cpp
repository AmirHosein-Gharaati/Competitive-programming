#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> dp;
int number;
const int inf = INT_MAX;

void solve(){
    dp[0]=0;

    for(int i = 1 ; i <= number ;i++ ){
        set<int> s;
        for (auto j: to_string(i)){
            s.insert(j-'0');
        }

        dp[i]=inf;

        for (auto j: s){
            dp[i] = min(dp[i],dp[i-j]+1);
        }
    }
} 

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> number;

    dp.assign(number+1, 0);
    dp[0] = 0;

    solve();
    cout << dp[number];

    return 0;
}