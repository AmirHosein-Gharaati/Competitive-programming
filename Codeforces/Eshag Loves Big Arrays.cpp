#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;


int main(){

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int minn = 110;
        mp.clear();
        
        for(int i = 0 ; i < n ; i++){
            int number;
            cin >> number;
            mp[number]++;
            if(minn > number) minn = number;
        }

        cout << n - mp[minn] << endl;
    }

    return 0;   
}