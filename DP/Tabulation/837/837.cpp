#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // dp[i] -> 有i點時的機率
    vector<double> dp;

    /*
        最簡單的dp想法
        為了湊到i點 -> 用i - j去湊
        每個機率轉移都是乘上 (1.0 / maxPts)
        但這樣要O(n * maxPts)會超時
        優化看下面
    */
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0)
            return 1;

        dp.assign(n + 5, 0);

        // dp[0] -> 0點是開始，機率是100%
        dp[0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= maxPts; ++j)
            {
                // 注意不要涵蓋到i - j >= k的區間
                // 因為遊戲在>= k時就結束了，不會再抽牌
                if (i - j >= 0 && i - j < k)
                {
                    dp[i] += dp[i - j] * (1.0 / maxPts);
                }
            }
        }

        // k ~ n都是答案
        double res = 0;
        for (int i = k; i <= n; ++i)
        {
            res += dp[i];
        }

        return res;
    }
};


class Solution 
{
public:
    // dp[i] -> 有i點時的機率
    vector<double> dp;

    /*
        由於上面的dp[i]需要算dp[i - j]的總和
        所以可以簡單的用滑動窗戶的方式維護所有合法的dp[i - j]
        這樣的話就能在O(n)解決
    */
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0)
            return 1;

        dp.assign(n + 5, 0);

        // dp[0] -> 0點是開始，機率是100%
        dp[0] = 1;

        // 滑動窗戶和
        double sum = dp[0];

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = sum * (1.0 / maxPts);
            if (i < k)
                sum += dp[i];
            // 注意i - maxPts不要涵蓋到i - maxPts >= k的區間
            // 因為遊戲在>= k時就結束了，不會再抽牌
            if (i - maxPts >= 0 && i - maxPts < k)
                sum -= dp[i - maxPts];
        }

        // k ~ n都是答案
        double res = 0;
        for (int i = k; i <= n; ++i)
        {
            res += dp[i];
        }

        return res;
    }
};


int main()
{
    Solution S;
    S.new21Game(10, 1, 10);

    return 0;
}