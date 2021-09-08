#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<pair<int, int>> times;

    int t;
    cin >> t;
    int lb=INT_MAX, ub=-1;
    for(int i = 0 ; i < t ; i++){
        int a, b;
        cin >> a >> b;

        times.push_back(make_pair(a, 1));
        times.push_back(make_pair(b, -1));
    }

    sort(times.begin(), times.end());

    int ans =0;
    int sum = 0;
    for(auto x : times){
        sum += x.second;
        ans = max(ans, sum);

    }

    cout << ans;


    return 0;
}