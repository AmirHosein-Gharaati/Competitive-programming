#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> ni(n);
    for(int i = 0 ;i < n ; i++){
        cin >> ni[i].first;
        ni[i].second = i;
    }

    sort(ni.begin(), ni.end());

    int counter = 1;
    int save_index = ni[0].second;

    for(int i = 1 ;i < n ;i++){
        int index = ni[i].second;
        if(ni[i].second < save_index)
            counter++;
        save_index = ni[i].second;
    }

    cout << counter;




    return 0;
}