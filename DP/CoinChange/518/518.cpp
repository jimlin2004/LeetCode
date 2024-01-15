#include <bits/stdc++.h>
using namespace std;

//coin change靶題
//dp[i][j] -> 只用前i個coins去湊出總共j的方法數
//dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]

class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        int dp[5005];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};