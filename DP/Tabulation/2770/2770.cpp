#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 算簡單的dp
    int maximumJumps(vector<int>& nums, int target) 
    {
        int dp[1005];
        memset(dp, -1, sizeof(dp)); // -1是到不了

        dp[0] = 0;

        int n = nums.size();
        for (int j = 1; j < n; ++j)
        {
            int res = 0;
            for (int i = 0; i < j; ++i)
            {
                if (dp[i] != -1 && abs(nums[j] - nums[i]) <= target)
                {
                    res = max(res, dp[i] + 1);
                }
            }
            if (res != 0)
                dp[j] = res;
        }

        return dp[n - 1];
    }
};