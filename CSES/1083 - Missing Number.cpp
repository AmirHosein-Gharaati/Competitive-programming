#include <bits/stdc++.h>

using namespace std;

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<int> nums;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        nums.insert(num);
    }

    for(int i = 1 ; i <= n; i++){
        if(nums.find(i) == nums.end()){
            cout << i;
            break;
        }
    }

    return 0;
}