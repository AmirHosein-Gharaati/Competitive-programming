#include <bits/stdc++.h>
using namespace std;

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> numbers(n);
    long long int summ = 0;
    
    for(int i = 0 ; i < n; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int median = numbers[n/2];

    long long res = 0;
    for(int i = 0 ; i < n ; i++){
        res += abs(numbers[i]-median);
    }

    cout << res;

    


    return 0;
}