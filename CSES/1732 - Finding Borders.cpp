#include <bits/stdc++.h>

using namespace std;

vector<int> KMP(string t)
{
    int n = t.size();
    vector<int> prefix(n);
    prefix[0] = 0;
    int k = 0;

    for (int i = 1; i < n; i++)
    {
        while (k > 0 && t[k] != t[i])
            k = prefix[k - 1];
        if (t[k] == t[i])
            k++;
        prefix[i] = k;
    }
    return prefix;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<int> v = KMP(str);
    vector<int> ans;

    int j = v[v.size() - 1];

    while (j > 0)
    {
        ans.push_back(j);
        j = v[j - 1];
    }

    sort(ans.begin(), ans.end());

    for (auto num : ans)
        cout << num << " ";

    return 0;
}