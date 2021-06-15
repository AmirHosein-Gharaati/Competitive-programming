#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> coins;
vector<ll> dp;

ll solve(int num){

    ll result = -1;

    if(dp[num] == -1) return 0;
    if(dp[num] != 0) return dp[num]+1;
    if(num == 0) return 1;

    for(int coin : coins){
        long long temp;
        if(result == -1){
            if(num-coin >= 0){
                temp = solve(num-coin);
                if(temp > 0){
                    result = temp;
                }
            }
        }
        else{
            if(num-coin >= 0){
                temp = solve(num-coin);
                if(temp > 0){
                    result = min(result, temp);
                }
            }
        }
    }
    
    if(result != -1){
        dp[num] = result;
    }
    else{
        dp[num] = -1;
    }
    // cout << num << " " << dp[num] << " " << endl;;

    return result == -1 ? 0 : result+1;

}

int main(){

    int n, x;
    cin >> n >> x;

    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        coins.push_back(num);
    }

    dp = vector<ll>(x+1, 0);
    solve(x);

    if(dp[x] <= 0) cout << -1;
    else cout << dp[x];

    return 0;
}