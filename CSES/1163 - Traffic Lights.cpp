#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    set<int> points{0, n};
    multiset<int> dist{n};

    int p;
    for (int i = 0; i < x; i++)
    {
        cin >> p;

        auto it1 = points.upper_bound(p);
        auto it2 = it1;
        --it2;

        dist.erase(dist.find(*it1 - *it2));

        dist.insert(p - *it2);
        dist.insert(*it1 - p);

        points.insert(p);

        auto ans = dist.end();
        --ans;
        cout << *ans << " ";
    }

    return 0;
}