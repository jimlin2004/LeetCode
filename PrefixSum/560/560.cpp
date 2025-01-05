#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //這題有正有負，不好做滑動窗戶
    //改成用前綴和優化一下的O(n ^ 2)枚舉
    int subarraySum(vector<int>& nums, int k) 
    {
        int prefix[20005];
        prefix[0] = 0;
        for (int i = 1; i <= nums.size(); ++i)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        int res = 0;
        for (int i = 1; i <= nums.size(); ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                if (prefix[i] - prefix[j - 1] == k)
                    ++res;
            }
        }
        return res;
    }
};