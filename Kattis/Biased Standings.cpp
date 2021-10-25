#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef pair<int, string> team;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int tt;
    cin >> tt;

    while(tt--){

        int n;
        cin >> n;
        priority_queue<team, vector<team>, greater<> > pq;

        for(int i = 0 ; i < n ; i++){
            string teamName;
            int place;
            cin >> teamName >> place;
            pq.push(make_pair(place, teamName));
        }

        int p = 1;
        int res = 0;
        while(!pq.empty()){
            team t = pq.top();
            pq.pop();
            res += abs(t.first - p);
            p++;
        }

        cout << res;
        if(tt != 0) cout << endl;
    }


    return 0;
}
