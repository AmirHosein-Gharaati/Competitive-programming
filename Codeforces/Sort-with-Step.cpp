#include <bits/stdc++.h>

using namespace std;

int main()
{

    int tt;
    cin >> tt;

    int n, k;
    for (int i = 0; i < tt; i++)
    {
        cin >> n >> k;

        vector<int> nums(n);

        int num;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            nums[j] = num;
        }

        vector<int> abses(n);
        for (int j = 0; j < n; j++)
        {
            abses[j] = abs(nums[j] - (j + 1));
        }

        vector<bool> correctPlaces(n, false);
        for (int j = 0; j < n; j++)
        {
            correctPlaces[j] = abses[j] % k == 0;
        }
        int res = count(correctPlaces.begin(), correctPlaces.end(), false);

        if (res > 2 || res == 1)
        {
            cout << -1 << endl;
        }
        else if (res == 2)
        {
            int first = -1;
            int second = -1;

            for (int ii = 0; ii < n; ii++)
            {
                if (!correctPlaces[ii])
                {
                    if (first == -1)
                    {
                        first = ii;
                    }
                    else
                    {
                        second = ii;
                        break;
                    }
                }
            }

            if (abs(nums[first] - (second + 1)) % k == 0 && abs(nums[second] - (first + 1)) % k == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}
