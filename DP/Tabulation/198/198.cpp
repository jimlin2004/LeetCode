#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int dp[105];
        memset(dp, 0, sizeof(dp));
        //只有兩個選擇: 搶i或不搶i
        //如果搶了i，i + 1天就不能搶，
        //如果不搶i，則當前dp[i]是i以前最大的利益
        if (nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};