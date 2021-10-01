#include <bits/stdc++.h>

using namespace std;

bool prefix(string s, int qLen){
    int len = s.length();
    vector<int> p(len);

    p[0] = -1;
    int j = -1;

    for(int i = 1 ; i < len ; i++){

        while( j >= 0 && s[j+1] != s[i])
            j = p[j];
        
        if(s[j+1] == s[i])
            j++;
        p[i] = j;
        if(j == qLen-1)
            return true;
    }
    
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        string str;
        cin >> str;

        int q;
        cin >> q;

        for(int i = 0 ; i < q ; i++){
            string query;
            cin >> query;

            auto res = prefix(query+"#"+str, query.length());
            if(res)
                cout << "y" << endl;
            else
                cout << "n" << endl;
        }
    }


    return 0;
}