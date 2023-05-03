#include <bits/stdc++.h>

using namespace std;

bool test(vector<int> nums, int k)
{
    int counter = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                counter++;
            }
        }
    }

    return counter == k;
}

int main()
{

    int tt;
    cin >> tt;

    int n, k;
    for (int i = 0; i < tt; i++)
    {
        cin >> n >> k;
        vector<int> nums(n, 1);

        bool res = false;
        int flag = 0;
        int current_negative_index = 0;

        while (count(nums.begin(), nums.end(), -1) <= n / 2)
        {
            res = test(nums, k);
            if (res)
            {
                cout << "YES" << endl;
                for (int num : nums)
                {
                    cout << num << " ";
                }
                cout << endl;
                flag = 1;
                break;
            }
            else
            {
                nums[current_negative_index++] = -1;
            }
        }

        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
