#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt,profit,sum=0;
    int max_profit = 0;
    cin >> tt;
    while (tt--){
        cin >> profit;
        sum += profit;
        if(sum < 0 ){
            sum -= profit;
            if(sum > max_profit){
                max_profit = sum;
            }
            sum = 0;
        }
        else if (sum > max_profit){
             max_profit = sum;
        }
    }

    if(sum > max_profit){
        max_profit = sum;
    }
    cout << max_profit;
    return 0;
}