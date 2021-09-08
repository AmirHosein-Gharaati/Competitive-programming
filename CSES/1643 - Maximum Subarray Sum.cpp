#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> numbers(n);
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    long long current_sum = 0;
    long long max_sum = INT_MIN;

    for(int i = 0 ;i < n ; i++){
        if(current_sum + numbers[i] > numbers[i]){
            current_sum = current_sum + numbers[i];
        }else{
            current_sum = numbers[i];
        }

        if(current_sum > max_sum){
            max_sum = current_sum;
        }

        // cout << current_sum << " " << max_sum << endl;
    }

    cout << max_sum;

    return 0;
}