#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int maxx = 1;
    int sum = 1;

    for(int i = 1 ; i < str.length() ; i++){
        if(str[i] == str[i-1]){
            sum++;
        }else{
            sum = 1;
        }
        maxx = max(maxx, sum);
    }

    cout << maxx;

    return 0;
}