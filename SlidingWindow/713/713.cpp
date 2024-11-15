#include <bits/stdc++.h>
using namespace std;

//滑動窗戶滑一滑就過了

class Solution 
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        long long lim = k;
        long long window = 1;
        int l = 0, r = 0;
        int res = 0;
        while (r < nums.size())
        {
            window *= nums[r];
            while (l <= r && window >= lim)
            {
                window /= nums[l];
                ++l;
            }
            res += (r - l) + 1;
            ++r;
        }
        return res;
    }
};