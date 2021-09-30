#include <bits/stdc++.h>
using namespace std;

int prefix(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    int j = -1;
    pi[0] = -1;

    for(int i = 1 ; i < n; i++){
        while(j >= 0 && s[j+1] != s[i])
            j = pi[j];
        if(s[j+1] == s[i])
            ++j;
        pi[i] = j;
    }
    
    return j;
}

int main(){

    string test;

    int tt;
    cin >> tt;
    while(tt--){
        cin >> test;
        int t = prefix(test);
        int l = test.length();

        if(l%(l-t-1))
            cout << l << endl;
        else
            cout << l-t-1 << endl;

        if(tt)
            cout << endl;
    }
    
    return 0;
}