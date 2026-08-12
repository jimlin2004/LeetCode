#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題，滑動窗戶滑一下就行了
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        unordered_map<int, int> windowCnts;
        
        int res = 0;
        
        int n = nums.size();
        int l = 0, r = 0;
        while (r < n)
        {
            int& cntRef = windowCnts[nums[r]];
            ++cntRef;
            while (cntRef > k)
            {
                --windowCnts[nums[l]];
                ++l;
            }

            res = max(res, r - l + 1);
            ++r;
        }

        return res;
    }
};