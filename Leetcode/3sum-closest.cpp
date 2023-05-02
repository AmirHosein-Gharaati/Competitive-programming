#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int diff = INT_MAX;
    int res = 0;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i, j, k;
    for (i = 0; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (abs(sum - target) <= abs(diff))
            {
                diff = abs(sum - target);
                res = sum;

                if (diff == 0)
                {
                    return res;
                }
            }

            if (sum <= target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return res;
}

int main()
{

    return 0;
}
