#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> res;
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
            if (sum == 0)
            {
                vector<int> temp(3);
                temp[0] = nums[i];
                temp[1] = nums[j];
                temp[2] = nums[k];
                res.insert(temp);
                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
        }
    }
    return vector<vector<int>>(res.begin(), res.end());
}

int main()
{

    return 0;
}
