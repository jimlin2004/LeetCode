#include <bits/stdc++.h>
using namespace std;

//其實就是coin change

class Solution 
{
public:
    int numSquares(int n) 
    {
        int dp[10005];
        memset(dp, 0x3f, sizeof(dp));
        int squares[105];
        for (int i = 0; i <= 100; ++i)
        {
            squares[i] = i * i;
        }

        dp[0] = 0;
        for (int i = 0; i <= 100; ++i)
        {
            for (int j = squares[i]; j <= n; ++j)
            {
                dp[j] = min(dp[j], dp[j - squares[i]] + 1);
            }
        }
        return dp[n];
    }
};