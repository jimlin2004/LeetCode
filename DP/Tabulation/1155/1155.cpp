#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution 
{
public:
    long long dp[35][1005]; //dp[幾個骰子][總和]

    int numRollsToTarget(int n, int k, int target) 
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        // 直接O(n * k * target)暴搜
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                for (int c = 1; c <= min(j, k); ++c)
                {
                    dp[i][j] += dp[i - 1][j - c];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[n][target];
    }
};