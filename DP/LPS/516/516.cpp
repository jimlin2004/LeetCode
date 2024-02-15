#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution 
{
public:
    //結論: LCS(s, reverse(s)) == LPS
    int longestPalindromeSubseq(string s) 
    {
        int dp[1005][1005];
        memset(dp, 0, sizeof(dp));
        string reversedStr;
        reversedStr.resize(s.size());
        reverse_copy(s.begin(), s.end(), reversedStr.begin());
        
        int n = s.size();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == reversedStr[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }
};