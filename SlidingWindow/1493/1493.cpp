#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 滑動窗戶維護最多一個0的subarray即可
    int longestSubarray(vector<int>& nums)
    {
        int n = nums.size();
        
        int cnt = 0; // window中有多少個0

        int res = 0;
        int l = 0, r = 0;
        while (r < n)
        {
            if (nums[r] == 0)
                ++cnt;
            while (cnt > 1) // 只能最多一個0
            {
                if (nums[l] == 0)
                    --cnt;
                ++l;
            }

            res = max(res, r - l);
            ++r;
        }

        return res;
    }
};