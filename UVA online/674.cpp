#include <bits/stdc++.h>

using namespace std;

#define N 4

int baseCoins[] = {1, 5, 10, 25, 50};
typedef unsigned long long ull;

ull coins[8000];

int main(){

    vector<int> indexes;
    int number;
    int mx = -1;
    while(scanf("%d", &number) != EOF){
        indexes.push_back(number);
        mx = max(mx, number);
    }

    for(int i = 0 ; i < 8000 ; i++) coins[i] = 0;
    coins[0] = 1;

    for(int i = 0 ; i <= N; i++){
        for(int j = baseCoins[i] ; j <= mx ; j++){
            coins[j] += coins[j - baseCoins[i]];
        }
    }

    for(int num : indexes){
        cout << coins[num] << endl;
    }


    return 0;
}