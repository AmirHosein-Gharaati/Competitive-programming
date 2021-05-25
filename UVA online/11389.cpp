#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr1[110];
    int arr2[110];

    int n, d, r;
    while(1){
        cin >> n >> d >> r;
        if(n + d + r == 0) break;

        for(int i = 0 ; i < n ;i++) cin >> arr1[i];
        for(int i = 0 ; i < n ;i++) cin >> arr2[i];
        sort(arr1, arr1+n);
        sort(arr2, arr2+n);

        int result = 0;
        for(int i = 0 ; i < n ; i++){
            result += max(arr1[i] + arr2[n-i-1] - d, 0) * r;
        }

        cout << result << endl;
    }


    return 0;
}