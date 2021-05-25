#include <bits/stdc++.h>

using namespace std;

vector<int> buttons;
vector<int> ans;

#define INF 100000

int main(){

    int tt;
    cin >> tt;
    while(tt--){
        int n, t;
        cin >> n >> t;
        buttons.clear();
        ans.assign(3601, INF);
        ans[0] = 0;

        for(int i = 0 ; i < n ; i++){
            int number;
            cin >> number;
            buttons.push_back(number);
        }

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int current = q.front();
            q.pop();

            for(int u : buttons){
                int next = current + u;
                next = max(0, min(3600, next));

                if(ans[current]+1 < ans[next]){
                    ans[next] = ans[current] + 1;
                    q.push(next);
                }
            }
        }

        for(int i = t ; i < 3601 ; i++){
            if(ans[i] != INF){
                cout << ans[i] << " " << i-t << endl;
                break;
            }
        }
        
    }



    return 0;
}