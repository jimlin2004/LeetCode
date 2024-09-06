#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
    dp[i][j] -> 字串i ~ j中共有多少種不同的palindromic subsequences
*/

class Solution 
{
public:
    int solve(const string& s, int i, int j)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
        {
            if (j - i == 1)
                return dp[i][j] = 3; //ex: aa -> 3個回文
            return dp[i][j] = (2 * solve(s, i + 1, j - 1)) % MOD;
        }
        return dp[i][j] = (solve(s, i + 1, j - 1) + solve(s, i, j - 1) + solve(s, i + 1, j)) % MOD;
    }

    int countPalindromicSubsequences(string s)
    {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < s.size(); ++i)
            dp[i][i] = 1;
        
        return solve(s, 0, s.size()) % MOD;
    }
private:
    const long long MOD = 1e9 + 7;
    long long dp[1005][1005];
};

int main()
{
    Solution s;
    s.countPalindromicSubsequences("bccb");
    return 0;
}