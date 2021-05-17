#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define N 21
ull dp[10010];
int coins[23];


int main(){
    

    vector<int> indexes;
    int number;
    int mx = -1;
    for(int i = 1 ; i <= N ; i++) coins[i] = i*i*i;

    while(scanf("%d", &number) != EOF){
        indexes.push_back(number);
        mx = max(mx, number);
    }

    
    
    for(int i = 0 ; i < 10001 ; i++) dp[i] = 0;
    dp[0] = 1;


    for(int i = 1 ; i <= N ; i++){
        for(int j = coins[i]; j <= mx ; j++){
            dp[j] += dp[j - coins[i]];
        }
    }


    for(int num : indexes){
        cout << dp[num] << endl;
    }


    return 0;
}