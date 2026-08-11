#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool vis[2505];

    // 水題
    int missingInteger(vector<int>& nums) 
    {
        int n = nums.size();

        int prefixSum = nums[0];

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == nums[i - 1] + 1)
                prefixSum += nums[i];
            else
                break;
        }

        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; ++i)
        {
            vis[nums[i]] = true;
        }

        int res = prefixSum;
        while (vis[res])
            ++res;
        return res;
    }
};