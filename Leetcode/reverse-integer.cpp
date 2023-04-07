#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
    vector<int> new_number;

    int sign = x >= 0 ? 1 : -1;
    long long new_x = x;

    if (new_x < 0)
        new_x *= -1;

    while (new_x != 0)
    {
        new_number.push_back(new_x % 10);
        new_x = new_x / 10;
    }

    long long res = 0;
    for (int i = 0; i < new_number.size(); i++)
    {
        res += new_number[i] * pow(10, new_number.size() - 1 - i);
    }

    if (res > pow(2, 31) - 1)
        return 0;
    if (res < -pow(2, 31) - 1)
        return 0;
    return res * sign;
}

int main()
{

    int x;
    cin >> x;

    int res = reverse(x);
    cout << res;

    return 0;
}
