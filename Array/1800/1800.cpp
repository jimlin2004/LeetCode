#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int maxAscendingSum(vector<int>& nums) 
    {
        int n = nums.size();
        int res = nums[0];
        int curr = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                curr += nums[i];
            }
            else
            {
                res = max(res, curr);
                curr = nums[i];
            }
        }
        res = max(res, curr);
        return res;
    }
};