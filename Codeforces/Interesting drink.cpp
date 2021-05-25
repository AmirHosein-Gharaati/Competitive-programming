#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
int dp[MAX];
int arr[MAX];

int main(){

    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));  
    memset(arr, 0, sizeof(arr));
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    arr[n] = MAX;

    int counter = 0;
    for(int i = 0 ;i < n ; i++){
        counter++;
        for(int j = arr[i] ; j < arr[i+1] ; j++){
            dp[j] = counter;
        }
    }

    int tt;
    cin >> tt;

    while(tt--){
        int num;
        cin >> num;
        if(num >= arr[n-1]) cout << n << endl;
        else
            cout << dp[num] << endl;
    }

    



    return 0;
}