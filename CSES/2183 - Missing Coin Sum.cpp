#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> numbers(n+1);
    for(int i = 1 ; i <= n ;i ++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    vector<long long> dp(1000000, 0);
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        if(dp[i-1] < numbers[i]){
            cout << dp[i-1];
            return 0;
        }
        dp[i] = dp[i-1] + numbers[i];
    }
    cout << dp[n];

    return 0;
}