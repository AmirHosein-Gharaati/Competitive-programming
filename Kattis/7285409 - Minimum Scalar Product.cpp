#include <bits/stdc++.h>

using namespace std;

#define MAX 900

int main(){

    long long v1[MAX], v2[MAX];

    int tt;
    cin >> tt;
    int n;
    for(int j = 0 ; j < tt ;j++){
        cin >> n;

        for(int i = 0 ; i < n ; i++) cin >> v1[i];
        for(int i = 0 ; i < n ; i++) cin >> v2[i];

        sort(v1, v1+n);
        sort(v2, v2+n, greater<int>());

        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += v1[i]*v2[i];
        }

        cout << "Case #" << j+1 << ": " << sum << endl;
    }



    return 0;
}