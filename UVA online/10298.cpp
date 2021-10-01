#include <bits/stdc++.h>

using namespace std;

int prefix(string s){

    int len = s.length();
    vector<int> p(len, 0);
    int j = -1;
    p[0] = -1;

    for(int i = 1 ; i < len ; i++){
        while(j>=0 && s[j+1] != s[i])
            j = p[j];
        if(s[j+1] == s[i])
            j++;
        p[i] = j;
    }

    return j;
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while(cin >> str && str != "."){
        auto index = prefix(str);
        // cout << index+1;
        int len = str.length();

        if(len%(len-index-1) != 0)
            cout << 1;
        else
            cout << len/(len-index-1);
        
        cout << endl;
    }

    return 0;
}