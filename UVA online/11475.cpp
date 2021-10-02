#include <bits/stdc++.h>

using namespace std;

vector<int> KMP(string t){
    int n = t.size();
    vector<int> prefix(n);
    prefix[0] = 0;
    int k = 0;

    for(int i = 1; i < n; i++) {
        while(k>0 && t[k] != t[i]) k = prefix[k-1];
        if(t[k] == t[i]) k++;
        prefix[i] = k;
    }
    return prefix;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text;
    while(cin >> text){
        string rev = text;
        reverse(rev.begin(), rev.end());

        string temp = rev + "#" + text;
        auto res = KMP(temp);
        int n = temp.size();
        int q = res[n-1];
        cout << text + rev.substr(q) << endl;
    }


    return 0;
}