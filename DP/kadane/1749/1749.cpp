#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    static const int maxn = 1e5 + 5;

    // 基本上就是kadane
    // 由於要abs，所以維護max與min
    // 然後每個地方都看有沒有最大的答案即可
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int dpMin[maxn];
        int dpMax[maxn];

        dpMin[0] = dpMax[0] = nums[0];

        int n = nums.size();
        int res = abs(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            dpMax[i] = max(dpMax[i - 1] + nums[i], nums[i]);
            dpMin[i] = min(dpMin[i - 1] + nums[i], nums[i]);
            res = max({res, abs(dpMax[i]), abs(dpMin[i])});
        }
        return res;
    }
};