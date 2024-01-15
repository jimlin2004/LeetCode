#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        int len = nums.size();
        for (int i = 1; i < len; i++)
        {
            if (nums[i] > dp.back())
                dp.push_back(nums[i]);
            else
                *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        }
        return dp.size();
    }
};