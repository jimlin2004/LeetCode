#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifference(vector<int>& nums)
    {
        /*
            因為最多只能操作三次
            觀察到替換數字相當於從array中移除該數字
            且要求的diff是arr的最大跟最小
            所以明顯要先對array做sort
            然後枚舉所有可能
            1. 移除最小的三個
            2. 移除最小的兩個與最大的一個
            3. 移除最小的一個與最大的兩個
            4. 移除最大的三個
        */

        int n = nums.size();

        // 可以全部變一樣
        if (n <= 3)
            return 0;

        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        // 最小三個
        diff = min(diff, nums.back() - nums[3]);
        // 最小兩個最大一個
        diff = min(diff, nums[n - 2] - nums[2]);
        // 最小一個最大兩個
        diff = min(diff, nums[n - 3] - nums[1]);
        // 最大三個
        diff = min(diff, nums[n - 4] - nums.front());

        return diff;
    }
};