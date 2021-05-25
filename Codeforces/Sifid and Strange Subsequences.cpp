#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(){

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        v.clear();

        for(int i = 0 ; i < n ; i++){
            int number;
            cin >> number;
            v.push_back(number);
        }

        sort(v.begin(), v.end());
        bool flag;
        while(n > 1){
            flag = true;
            for(int i = 0 ; i < n-1 ; i++){
                // cout << v[i] << " " << v[i+1] << endl;

                if(abs(v[i+1]-v[i]) < v[n-1]){
                    v.pop_back();
                    n--;
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }

        cout << n << endl;

    }




    return 0;
}