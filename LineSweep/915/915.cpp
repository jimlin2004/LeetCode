#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

class Solution 
{
public:
    // 預處理right[]然後掃一遍就有答案
    int partitionDisjoint(vector<int>& nums)
    {
        int n = nums.size();

        int right[maxn]; // 右邊(包含)的最小值

        right[n] = 0x3f3f3f3f;
        for (int i = n - 1; i >= 0; --i)
            right[i] = min(nums[i], right[i + 1]);
        
        int res;

        int currMax = nums[0]; // 當前最大值
        for (int i = 1; i < n; ++i)
        {
            if (currMax <= right[i])
            {
                res = i;
                break;
            }
            currMax = max(nums[i], currMax);
        }

        return res;
    }
};