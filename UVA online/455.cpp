#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){

    int index = 0;
    string test;

    int tt;
    cin >> tt;
    while(tt--){
        cin >> test;
        vector<int> res = prefix(test);
        int i;
        for(i = 0 ; i < res.size(); i++){
            // if(res[i] != 0){
            //     index = i;
            //     break;
            // }
            cout << res[i] << " " << test[i] << endl;
        }

        cout << index;
        if(tt != 0)
            cout << endl << endl;
    }
    
    
    

    return 0;
}