#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int dp[105];
    // 簡單dp題，只是邊界條件有點多
    int numDecodings(string s) 
    {
        if (s[0] == '0')
            return 0;
        
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }

    int solve(const string& s, int i)
    {
        if (i == s.size())
            return 1;
        if (i > s.size())
            return 0;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        int cnt = 0;
        
        int curr = s[i] - '0';
        cnt += solve(s, i + 1);
        curr = curr *10 + s[i + 1] - '0';
        if (curr <= 26)
            cnt += solve(s, i + 2);
        
        return dp[i] = cnt;
    }
};


int main()
{
    string input = "12";
    Solution S;
    S.numDecodings(input);

    return 0;
}