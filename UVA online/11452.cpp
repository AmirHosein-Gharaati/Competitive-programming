#include <bits/stdc++.h>

using namespace std;
#define MAX 2010

int prefix(string s){
    int len = s.length();
    vector<int> p(len, 0);
    int j = -1;
    p[0] = -1;

    for(int i = 1 ; i < len ; i++){

        while(j >= 0 && s[j+1] != s[i])
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

    int tt;
    cin >> tt;
    string temp;
    getline(cin, temp);

    while(tt--){
        string line;
        
        getline(cin ,line);

        auto res = prefix(line);

        for(int i = res+1, count = 0 ; count < 8 ;count++){
            if(i >= line.length())
                i = res+1;
            cout << line[i];
            i++;
        }

        cout << "...\n";
    }
    


    return 0;
}