#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n);

    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int curr_len = 0;
    int max_len = 0;
    int left = 0;
    int right = 0;

    while(right < n)
    {
        if(freq.find(arr[right]) == freq.end() || freq[arr[right]] == 0) {
            curr_len++;
            max_len = max(max_len, curr_len);

            freq[arr[right]]++;
            right++;

        } else {
            curr_len--;
            freq[arr[left]]--;
            left++;
        }
    }

    cout << max_len;

    return 0;
}