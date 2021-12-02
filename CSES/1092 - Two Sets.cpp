#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if((n*(n+1)/2)%2 != 0){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    int sum = 0;
    unordered_set<int> s;
    s.reserve(n);

    int target = (n*(n+1)/2)/2;
    // cout << target << endl;

    int i = n;

    while(sum < target){
        s.insert(i);
        sum += i;
        i--;
        if(sum > target) {
            sum -= (i+1);
            s.erase(s.find(i+1));
            s.insert(target - sum);
        }
    }

    cout << s.size() << endl;

    for(auto ele: s) {
        cout << ele << " ";
    }

    cout << endl;
    cout << n- s.size() << endl;
    
    for(int i = 1 ; i <= n ; i++){
        if(s.find(i) == s.end()){
            cout << i << " ";
        }
    }
    

    return 0;
}