#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int maximumDifference(vector<int>& nums) 
    {
        int minV = nums[0];
        int res = -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (minV != nums[i])
                res = max(res, nums[i] - minV);
            minV = min(minV, nums[i]);
        }

        return res;
    }
};