#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        /*
            嘗試所有可能
            1. 最小的三個
            2. 最小的兩個，最大一個
            3. 最小的一個，最大兩個
            4. 最大的三個
        */
        int n = nums.size();

        return max({
            nums[0] * nums[1] * nums[2],
            nums[0] * nums[1] * nums[n - 1],
            nums[0] * nums[n - 2] * nums[n - 1],
            nums[n - 3] * nums[n - 2] * nums[n - 1]
        });
    }
};