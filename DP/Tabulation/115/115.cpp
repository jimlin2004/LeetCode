#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        從s中找到所有subsequence是t的個數

        dp[i][j] -> 用s的前i個字元，可以湊出t的前t個字元的subsequence數量

        當目前匹配s[i - 1]與t[j - 1]時
        1. s[i - 1] != t[j - 1]
        此時只能放棄s[i - 1]
        所以dp[i][j] = dp[i - 1][j]
        2. s[i - 1] == t[j - 1]
        此時s[i - 1]可用可不用
        所以dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]

        因為dp[i]只與dp[i - 1]有關，所以還可以滾動優化

        記得要用unsigned long long，否則會炸
    */

    static inline vector<vector<unsigned long long>> dp;

    int numDistinct(string s, string t) 
    {
        int m = s.size();
        int n = t.size();
        dp.assign(m + 5, vector<unsigned long long>(n + 5));

        // 邊界條件
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = 1; // 無論s有多少字元，湊出空字串只有1種方式
        for (int j = 1; j <= n; ++j)
            dp[0][j] = 0; // s沒有字元，都沒辦法湊出字串

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] != t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else // s[i - 1] == t[j - 1]
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
            }
        }

        return (int)dp[m][n];
    }
};