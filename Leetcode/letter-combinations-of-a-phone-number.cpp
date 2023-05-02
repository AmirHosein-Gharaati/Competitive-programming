#include <bits/stdc++.h>

using namespace std;

void helper(string table[], string &digits, int start, string &s, vector<string> &res)
{
    if (start == digits.size())
    {
        res.push_back(s);
        return;
    }

    int i = digits[start] - '2';

    for (int j = 0; j < table[i].size(); j++)
    {
        s.push_back(table[i][j]);
        helper(table, digits, start + 1, s, res);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    map<char, string> num2letters;
    string table[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;

    if (digits.empty())
    {
        return result;
    }

    string s;
    helper(table, digits, 0, s, result);
    return result;
}

int main()
{

    return 0;
}
