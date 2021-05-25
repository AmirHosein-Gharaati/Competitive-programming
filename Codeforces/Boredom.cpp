#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
typedef long long ll;

int main(){

    int n;
    cin >> n;

    int arr[MAX];
    int maxx = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        maxx = max(maxx, arr[i]);
    }

    ll count[MAX];
    memset(count, 0, sizeof(count));

    for(int i = 0 ; i < n ; i++) count[arr[i]]++;

    ll dp[MAX];
    dp[0] = 0;
    dp[1] = count[1];
    for(int i = 2; i <= maxx ; i++){
        dp[i] = max(dp[i-1], i*count[i] + dp[i-2]);
    }

    cout << dp[maxx] ;


    return 0;
}