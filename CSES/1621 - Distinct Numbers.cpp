#include <bits/stdc++.h>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    set<int> nums;

    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        nums.insert(a);
    }

    cout << nums.size();



    return 0;
}