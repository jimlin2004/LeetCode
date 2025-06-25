#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // dp[i][j][c] = LPS len -> s[i ~ j]改最多k次時的最長LPS長度
    int dp[205][205][205];

    int longestPalindromicSubsequence(string s, int k) 
    {
        memset(dp, 0, sizeof(dp));

        int n = s.size();

        for (int i = 0; i <= n; ++i)
        {
            for (int c = 0; c <= k; ++c)
            {
                dp[i][i][c] = 1;
            }
        }

        for (int l = 2; l <= n; ++l)
        {
            for (int i = 0; i < n; ++i)
            {
                int j = i + l - 1;
                if (j >= n)
                    break;

                int cost = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));

                for (int c = 0; c <= k; ++c)
                {
                    // 不改變i或j的字
                    dp[i][j][c] = max(dp[i + 1][j][c], dp[i][j - 1][c]);

                    if (c >= cost)
                    {
                        // 改一個字或是不用改(因為如果s[i] == s[j]，cost是0)
                        dp[i][j][c] = max(dp[i][j][c], dp[i + 1][j - 1][c - cost] + 2);
                    }
                }
            }
        }

        return dp[0][n - 1][k];
    }
};