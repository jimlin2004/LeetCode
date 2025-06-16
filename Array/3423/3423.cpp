#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 水~~~
    int maxAdjacentDistance(vector<int>& nums) 
    {
        int res = abs(nums[0] - nums.back());
        for (int i = 1; i < nums.size(); ++i)
        {
            res = max(res, abs(nums[i - 1] - nums[i]));
        }

        return res;
    }
};