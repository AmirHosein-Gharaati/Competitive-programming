#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n)
{
    if (x == 0)
        return x;
    if (n == 0)
        return 1;

    if (n & 1)
    {
        if (n > 0)
            return x * pow(myPow(x, n / 2), 2);
        else
            return (1 / x) * pow(myPow(x, n / 2), 2);
    }
    else
        return pow(myPow(x, n / 2), 2);
}

int main()
{

    double x, n;

    cin >> x >> n;

    cout << fixed << setprecision(5);

    cout << myPow(x, n);

    return 0;
}