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

    vector<int> res = KMP(str);
    vector<int> ans;

    for (auto num : res)
        cout << num << " ";

    // int flag = 0;
    // for (int i = 0; i < res.size(); i++)
    // {
    //     if (res[i] != 0 && flag == 0)
    //     {
    //         flag = 1;
    //     }
    //     else if (res[i] == 0 && flag == 1)
    //     {
    //         flag = 2;
    //         break;
    //     }
    // }
    // if (flag == 2)
    // {
    //     cout << res.size() << endl;
    //     return 0;
    // }

    // int i;
    // for (i = 0; i < res.size(); i++)
    // {
    //     if (res[i] != 0)
    //     {
    //         ans.push_back(i);
    //         break;
    //     }
    // }

    // int size = i;

    // while ((i += size) < res.size())
    // {
    //     ans.push_back(i);
    // }
    // ans.push_back(res.size());

    // for (auto num : ans)
    //     cout << num << " ";

    return 0;
}