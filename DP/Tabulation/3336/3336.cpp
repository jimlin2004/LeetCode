#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        DP題，有參考題解

        (使用1-based)
        定義dp[i][j][k] = cnt代表現在的最新數字是nums[i]，
        第一個seq的GCD是j，第二個seq的GCD是k，pair數有cnt個

        因為兩個seq的元素不能重複，所以有以下轉移式
        考慮將新的nums[i]加入第一個seq，
        共有dp[i - 1][GCD(j, nums[i])][k]種
        將新的nums[i]加入第二個seq，
        共有dp[i - 1][j][GCD(nums[i], k)]

        然後因為是seuquence，所以nums[i]也可以都不選
        共有dp[i - 1][j][k]種

        所以dp轉移式
        dp[i][j][k] = dp[i - 1][j][k] 
                      + sum_{j'} dp[i - 1][j'][k] (where j = GCD(j', nums[i]))
                      + sum_{k'} dp[i - 1][j][k'] (where k = GCD(k', nums[i]))
        
        然後這個需要每次往前for loop
        更好的方法是往後加
        也就是
        dp[i][j][k] += dp[i - 1][j][k]
        dp[i][GCD(j, nums[i])][k] += dp[i - 1][j][k]
        dp[i][j][GCD(k, nums[i])] += dp[i - 1][j][k]

        然後邊界條件是dp[0][0][0] = 1
        定義gcd = 0是代表seq是空的
    */

    const int MOD = 1000000007;

    // dp可以用滾動陣列
    int dp[205][205][205];

    int subsequencePairCount(vector<int>& nums)
    {
        memset(dp, 0, sizeof(dp));

        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());

        // GCD不會大於max{nums}
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j) // 記得從0開始
            {
                int gcd1 = gcd(j, nums[i - 1]);

                for (int k = 0; k <= m; ++k) // 記得從0開始
                {
                    int gcd2 = gcd(k, nums[i - 1]);

                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % MOD;
                    dp[i][gcd1][k] = (dp[i][gcd1][k] + dp[i - 1][j][k]) % MOD;
                    dp[i][j][gcd2] = (dp[i][j][gcd2] + dp[i - 1][j][k]) % MOD;
                }
            }
        }

        // 答案在所有的dp[n][i][i];
        int res = 0;
        for (int i = 1; i <= m; ++i)
        {
            res = (res + dp[n][i][i]) % MOD;
        }

        return res;
    }
};