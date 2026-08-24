#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        dp[i][m] -> 在第i個石頭的時候最多拿m個時的最大值
        轉移式看下方
    */
    bool vis[105][105];
    int dp[105][105];
    int suffixSum[105];

    int solve(int i, int m, const vector<int>& piles)
    {
        int n = piles.size();

        if (i >= n)
            return 0;
        
        if (vis[i][m])
            return dp[i][m];

        vis[i][m] = true;

        if (i + 2 * m >= n) // 剩下可以全拿
            return dp[i][m] = suffixSum[i];

        dp[i][m] = INT_MIN;

        for (int x = 1; x <= 2 * m; ++x)
        {
            // 本次能拿到的 = 剩下的石頭 - 對手在(i + x)時能拿到的最大值
            int opponentMax = solve(i + x, max(m, x), piles);
            int myTake = suffixSum[i] - opponentMax;

            dp[i][m] = max(dp[i][m], myTake);
        }

        return dp[i][m];
    }

    int stoneGameII(vector<int>& piles) 
    {
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));

        int n = piles.size();
        
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffixSum[i] = suffixSum[i + 1] + piles[i];

        return solve(0, 1, piles);
    }
};