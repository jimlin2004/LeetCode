#include <bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
        int maxRepeating(string sequence, string word) 
        {
            int dp[105]; //記著到dp[i]為止有多少連續的word
            memset(dp, 0, sizeof(dp));

            int n = sequence.size();
            int m = word.size();

            int res = 0;

            for (int i = m; i <= n; ++i)
            {
                if (sequence.substr(i - m, m) == word)
                    dp[i] = dp[i - m] + 1;
            
                res = max(dp[i], res);
            }

            return res;
        }
};