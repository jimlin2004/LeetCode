#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 直接用bits暴力枚舉subset即可
    int countMaxOrSubsets(vector<int>& nums)
    {
        int n = nums.size();

        // 最大的一定是全部or起來
        int maxOr = 0;
        for (int val: nums)
            maxOr |= val;

        int res = 0;

        // 直接bit枚舉subset
        int limit = (1 << n);

        for (int i = 0; i < limit; ++i)
        {
            int curr = 0;

            int bits = i;

            for (int j = 0; j < n; ++j)
            {
                if (bits & 1)
                    curr |= nums[j];
                bits >>= 1;
            }

            if (curr == maxOr)
                ++res;
        }

        return res;
    }
};