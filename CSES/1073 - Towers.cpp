#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int k;

    multiset<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> k;

        auto it = ans.upper_bound(k);

        if (it == ans.end())
            ans.insert(k);

        else
        {
            ans.erase(it);
            ans.insert(k);
        }
    }

    cout << ans.size();

    return 0;
}