#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (amount == 0)
            return 0;
        int dp[10005];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == 0x3f3f3f3f)
            return -1;
        return dp[amount];
    }
};

int main()
{
    Solution s;
    vector<int> test = {1, 2, 5};
    s.coinChange(test, 11);
}