#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;

    for(int t = 1 ; t <= tt ; t++){

        int n;
        cin >> n;
        vector<int> reds, blacks;
        string s;

        for(int i = 0 ; i < n ; i++){
            cin >> s;
            int num = stoi(s.substr(0, s.length()-1));
            if(s[s.length()-1] == 'R')
                reds.push_back(num);
            else
                blacks.push_back(num);
        }

        if(reds.empty() || blacks.empty()){
            cout << "Case #" << t << ": 0" << endl;
            continue;
        }

        sort(reds.begin(), reds.end());
        sort(blacks.begin(), blacks.end());

        vector<int> ans;
        while(!reds.empty() && !blacks.empty()){
            int r = reds.back();
            int b = blacks.back();

            reds.pop_back();
            blacks.pop_back();

            ans.push_back(r);
            ans.push_back(b);
        }

        int sum = 0;
        for(auto ele : ans) sum += ele;
        sum -= ans.size();

        cout << "Case #" << t << ": " << sum << endl;

    }


    return 0;
}