#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 題意: 挑出只出現在一個subarray的最大數字
    // 分情況討論
    int largestInteger(vector<int>& nums, int k)
    {
        int n = nums.size();

        if (k == 1) // 挑只出現一次且最大的數字
        {
            vector<int> cnts(55, 0);
            for (int num: nums)
                ++cnts[num];
            int res = -1;
            for (int i = 0; i < cnts.size(); ++i)
            {
                if (cnts[i] == 1)
                    res = i;
            }

            return res;
        }

        if (k == n) // 挑整個nums中最大的
        {
            return *max_element(nums.begin(), nums.end());
        }

        vector<int> cnts(55, 0);
        for (int num: nums)
            ++cnts[num];
        // 到這裡只有nums[0]跟nums[n - 1]才會只出現在一個subarray
        if (cnts[nums[0]] > 1 && cnts[nums[n - 1]] > 1)
            return -1;
        else if (cnts[nums[0]] == 1 && cnts[nums[n - 1]] == 1)
            return max(nums[0], nums[n - 1]);
        else if (cnts[nums[0]] == 1)
            return nums[0];
        return nums[n - 1];
    }
};