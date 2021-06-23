#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int, int> ii;

vector<vector<int>> g;
vector<ii> nodes;
map<int ,int> nums, nums_rev;
int n;
int number;

vector<bool> used;
vector<int> mt, mt2;

bool try_kuhn(int u){

    if(used[u]) return false;

    used[u] = true;

    for(int to : g[u]){
        if(mt[to] == -1 || try_kuhn(mt[to])){
            mt[to] = u;
            mt2[u] = to;
            return true;
        }
    }

    return false;
}


bool solve(){

    mt.assign(number+1, -1);
    mt2.assign(n+1, -1);

    int counter = 0;
    for(int i = 0 ; i < n ; i++){
        used.assign(n+1, false);
        if(try_kuhn(i)) counter++;
    }

    return counter == n;

}

signed main(){

    // for presentation error (?)
    bool flag = true;

    while(scanf("%d", &n) != EOF){
        if(!flag)
            cout << endl;

        flag = false;

        g.clear();
        g.resize(n+1);
        nodes.clear();
        number = 1;
        nums.clear();
        nums_rev.clear();

        for(int i = 0 ; i < n ; i++){
            ii temp;
            int temp_int;
            cin >> temp.first >> temp.second;
            nodes.push_back(temp);

            temp_int = temp.first*temp.second;
            if(nums.count(temp_int) == 0){
                nums[temp_int] = number;
                nums_rev[number] = temp_int;
                number++;
            }
            g[i].push_back(nums[temp_int]);


            temp_int = temp.first+temp.second;
            if(nums.count(temp_int) == 0){
                nums[temp_int] = number;
                nums_rev[number] = temp_int;
                number++;
            }
            g[i].push_back(nums[temp_int]);


            temp_int = temp.first-temp.second;
            if(nums.count(temp_int) == 0){
                nums[temp_int] = number;
                nums_rev[number] = temp_int;
                number++;
            }
            g[i].push_back(nums[temp_int]);
        }

        if(solve()){
            for(int i = 0 ; i< n ; i++){
                char op;
                int res;
                int a = nodes[i].first;
                int b = nodes[i].second;
                
                if(a*b == nums_rev[mt2[i]]){
                    op = '*';
                }
                else if(a-b == nums_rev[mt2[i]]){
                    op = '-';
                }
                else if(a+b == nums_rev[mt2[i]]){
                    op = '+';
                }
                res = nums_rev[mt2[i]];

                cout << a << " " << op << " " << b << " = " << res;
                if(i != n-1) cout << endl;
            }
        }
        else{
            cout << "impossible";
        }
    }



    return 0;
}