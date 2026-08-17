#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prefixSum[505];
    // dp[i][j] -> 面對i ~ j時Alice能夠獲得的最高分數
    int dp[505][505];

    int solve(int i, int j)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = 0;

        // 右邊不能是空集合，所以m < j
        for (int m = i; m < j; ++m)
        {
            int leftSum = prefixSum[m] - prefixSum[i - 1];
            int rightSum = prefixSum[j] - prefixSum[m];
            if (leftSum == rightSum)
            {
                res = max({res, leftSum + solve(i, m), rightSum + solve(m + 1, j)});
            }
            else if (leftSum < rightSum)
            {
                res = max(res, leftSum + solve(i, m));
            }
            else
            {
                res = max(res, rightSum + solve(m + 1, j));
            }
        }

        return dp[i][j] = res;
    }

    // 一般的區間dp模板題，切兩邊選最好的那邊繼續
    int stoneGameV(vector<int>& stoneValue)
    {
        int n = stoneValue.size();

        prefixSum[0] = 0;
        for (int i = 1; i <= n; ++i)
            prefixSum[i] = prefixSum[i - 1] + stoneValue[i - 1];

        memset(dp, -1, sizeof(dp));

        return solve(1, n);
    }
};