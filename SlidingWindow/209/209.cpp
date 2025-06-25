#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();

        int res = 0x3f3f3f3f;
        int l = 0, r = 0;
        int curr = 0;
        while (r < n)
        {
            curr += nums[r];
            while (curr >= target)
            {
                res = min(res, r - l + 1);
                curr -= nums[l];
                ++l;
            }
            ++r;
        }

        return (res == 0x3f3f3f3f) ? 0 : res;
    }
};