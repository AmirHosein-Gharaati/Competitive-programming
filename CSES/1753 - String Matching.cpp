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

    string mainStr, sub;
    cin >> mainStr >> sub;
    int counter = 0;
    
    mainStr =  sub + "#" + mainStr;
    vector<int> res =  prefix(mainStr);
    for(int i = 0 ; i < res.size(); i++){
        if(res[i] == sub.length()){
            counter++;
        }
    }

    cout << counter ;

    return 0;
}