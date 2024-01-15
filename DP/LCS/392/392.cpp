#include <bits/stdc++.h>
using namespace std;

//LCS解法O(s * t)

class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int dp[105][10005];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 0;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return (dp[s.size()][t.size()] == s.size());
    }
};