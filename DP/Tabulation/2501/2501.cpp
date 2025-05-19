#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    unordered_map<long long, int> dp; // 離散化dp空間

    int longestSquareStreak(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int m = unique(nums.begin(), nums.end()) - nums.begin();

        int res = -1;

        for (int i = 0; i < m; ++i)
        {
            long long square = (long long)nums[i] * nums[i];
            if (dp[nums[i]] == 0)
                dp[nums[i]] = 1;
            dp[square] = dp[nums[i]] + 1; // 往前做
            res = max(res, dp[nums[i]]);
        }

        return res >= 2 ? res : -1;
    }
};