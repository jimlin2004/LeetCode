#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    { 
        int L = nums.size();
        vector<int> dp(L);
        dp[0] = nums[0];
        int max_num = dp[0];
        for (int i = 1; i < L; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            max_num = max(max_num, dp[i]);
        }
        return max_num;
    }
};