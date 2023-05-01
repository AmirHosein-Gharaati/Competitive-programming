#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
        return "";

    int ans = __INT_MAX__;
    for (int i = 0; i < strs.size() - 1; i++)
    {
        int foo = min(strs[i].size(), strs[i + 1].size());
        ans = min(ans, foo);
        while (strs[i].substr(0, ans) != strs[i + 1].substr(0, ans))
        {
            ans--;
        }
        if (ans == 0)
            return "";
    }
    return strs[0].substr(0, ans);
}

int main()
{

    return 0;
}
