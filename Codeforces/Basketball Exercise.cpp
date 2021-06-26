#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> a, b;

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    vector<int> dp(2);
    dp[0] = dp[1] = 0;

    for(int i = 0 ; i < n ; i++){
        int x, y;
        x = max(dp[0], dp[1]+a[i]);
        y = max(dp[1], dp[0]+b[i]);

        dp[0] = x;
        dp[1] = y;
    }

    cout << max(dp[0], dp[1]);


    return 0;
}