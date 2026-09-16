#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        這題題目描述講得很糟，其實就是
        給定數線[0, n - 1]中
        請挑出k個不重疊的線段(端點可共用)
        有幾種方法

        直覺地會想到dp[i][k] -> 用前i個點，畫好k個線段的方法數
        轉移式:
        1. 第i個點不當作新的線段右端點
            dp[i][k] = dp[i - 1][k]
        2. 第i個點作為第k條線段的右端點
        此時需要枚舉第k條線段的左端點
        總共是 sum_{j = 1}^{i - 1} dp[j][k - 1]

        明顯需要前綴和加速
        令S[i][k - 1] = sum_{j = 1}^{i - 1} dp[j][k - 1]

        所以最後轉移式:
        dp[i][k] = dp[i - 1][k] + S[i - 1][k - 1]

        就能在O(nk)解決這題
    */

    const int MOD = 1e9 + 7;
    int dp[1005][1005];
    int prefixSum[1005][1005];

    int numberOfSets(int n, int k) 
    {
        memset(prefixSum, 0, sizeof(prefixSum));

        // base case: 畫0條線段只有1種方法
        dp[1][0] = 1;
        prefixSum[1][0] = 1;
        
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                // 不以i為結尾
                dp[i][j] = dp[i - 1][j];
                // 以第i個點為結尾
                if (j > 0)
                {
                    dp[i][j] = (dp[i][j] + prefixSum[i - 1][j - 1]) % MOD;
                }
            }

            // 前綴和優化
            for (int j = 0; j <= k; ++j)
                prefixSum[i][j] = (prefixSum[i - 1][j] + dp[i][j]) % MOD;
        }

        return dp[n][k];
    }
};