#include <bits/stdc++.h>

using namespace std;

bool arry(string a,string b){
    if(b.size()<a.size())
        return false;

    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

vector<string>nums;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;
    int n;

    while(tt--) {
        cin >> n;

        nums = vector<string>(n);

        for(int i = 0 ; i < n; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        int flag = true;
        for(int i = 0 ; i < n-1; i++) {
            if(arry(nums[i], nums[i+1])) {
                flag = false;
                break;
            }
        }

        if(flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
