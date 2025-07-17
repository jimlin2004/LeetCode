#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // dp[i][j] -> 序列中第-2個 mod k = i且第-1個 mod k = j
    // 因為假設一個序列兩兩相加 mod k = val
    // 則序列一定是 a, b, a, b, a, b, ...
    // 且(a + b) mod k = val
    // 所以轉移式是簡單的dp[i][j] = dp[j][i] + 1
    // 也就是每次加上一個j到序列的尾巴
    int dp[1005][1005];  

    int maximumLength(vector<int>& nums, int k) 
    {
        memset(dp, 0, sizeof(dp));

        int res = 0;
        for (int num: nums)
        {
            int j = num % k;
            // 枚舉目前的最後一個
            for (int i = 0; i < k; ++i)
            {
                dp[i][j] = dp[j][i] + 1;
                res = max(res, dp[i][j]); 
            }
        }

        return res;
    }
};