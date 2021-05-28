#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> v;
    for(int i = 0 ; i < n ; i++) v.push_back(0);

    string s;
    for(int i = 0 ; i < m ; i++){
        cin >> s;
        for(int j = 0 ; j < n ; j++){
            if(s[j] == 'W')
                v.at(j)++;
        }
    }

    for(int number : v){
        if(number%2 == 0){
            cout << "B";
        } else{
            cout << "F";
        }
    }




    return 0;
}