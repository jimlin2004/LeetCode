#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int findMiddleIndex(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> prefix(n + 5, 0);

        for (int i = 1; i <= n; ++i)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int res = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (prefix[i - 1] == prefix[n] - prefix[i])
            {
                res = i - 1;
                break;
            }
        }

        return res;
    }
};