#include <bits/stdc++.h>
using namespace std;

/*
    l = 1, r = 3, n = 3
    [1, 2, 1], [1, 3, 1], [1, 3, 2]
    [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
    [3, 1, 2], [3, 1, 3], [3, 2, 3]

    有[1]時後面可以接2, 3
    [1, 2]後面只能接 1
    [1, 3]後面能接 2, 1

    dp[i][j][k]
    -> 到第i個數字的時候最後面是j，k 0/1是結尾下降或上升

    dp[i][j][0] = dp[i - 1][j + 1][1] + dp[i - 1][j + 2][1] + ...
    dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 2][0] + ...

    為了加速
    需要額外有prefix sum
    
    結果時間很緊，用memset會TLE，目前2.77秒才過
    可能還可以用滾動陣列優化
*/

class Solution
{
private:
    int dp[2005][2005][2];
    int prefixSum[2005][2005][2];

    const int MOD = 1000000007;
public:
    int zigZagArrays(int n, int l, int r)
    {
        // memset(dp, 0, sizeof(dp));
        // memset(prefixSum, 0, sizeof(prefixSum));
        for (int i = 1; i <= n; ++i) {
            dp[i][l - 1][0] = dp[i][l - 1][1] = 0;
            prefixSum[i][l - 1][0] = prefixSum[i][l - 1][1] = 0;
        }

        // 只有1個數字時答案只有1個
        for (int j = l; j <= r; ++j)
        {
            dp[1][j][0] = 1;
            prefixSum[1][j][0] = (prefixSum[1][j][0] + prefixSum[1][j - 1][0] + 1) % MOD;
            dp[1][j][1] = 1;
            prefixSum[1][j][1] = (prefixSum[1][j][1] + prefixSum[1][j - 1][1] + 1) % MOD; 
        }

        for (int i = 2; i <= n; ++i)
        {
            for (int j = l; j <= r; ++j)
            {
                // k == 1
                // for (int v = l; v < j; ++v)
                // {
                    // dp[i][j][1] += dp[i - 1][v][0];
                // }
                dp[i][j][1] = (prefixSum[i - 1][j - 1][0] - prefixSum[i - 1][l - 1][0] + MOD) % MOD;
                prefixSum[i][j][1] = (prefixSum[i][j - 1][1] + dp[i][j][1]) % MOD;

                // k == 0
                // for (int v = j + 1; v <= r; ++v)
                // {
                    // dp[i][j][0] += dp[i - 1][v][1];
                // }
                dp[i][j][0] = (prefixSum[i - 1][r][1] - prefixSum[i - 1][j][1] + MOD) % MOD;
                prefixSum[i][j][0] = (prefixSum[i][j - 1][0] + dp[i][j][0]) % MOD;
            }
        }

        // 把長度為 n 的所有可能加起來
        // int ans = 0;
        // for (int j = l; j <= r; ++j)
        // {
        //     ans += dp[n][j][0];
        //     ans += dp[n][j][1];
        // }
        int ans = (prefixSum[n][r][0] - prefixSum[n][l - 1][0] + MOD) % MOD + (prefixSum[n][r][1] - prefixSum[n][l - 1][1] + MOD) % MOD;

        return ans % MOD;
    }
};

int main()
{
    Solution sol;
    sol.zigZagArrays(3, 1, 3);

    return 0;
}