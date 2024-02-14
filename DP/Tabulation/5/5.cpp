#include <string>
#include <cstring>
using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if (s.size() <= 1)
            return s;
        int maxLen = 1;
        int start = 0;
        int end = 0;
        //dp[i][j] -> s[i ~ j]是不是一個回文子字串
        bool dp[1005][1005];
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < s.size(); ++i)
            dp[i][i] = true;
        //O(n^2)
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1]))
                {
                    dp[j][i] = true;
                    if (i - j + 1 > maxLen)
                    {
                        maxLen = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};