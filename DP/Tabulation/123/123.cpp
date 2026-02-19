#include <bits/stdc++.h>
using namespace std;


class Solution 
{
private:
    // dp[第幾天][有沒有股票][操作幾次了]的最大獲利
    int dp[100005][2][3];
public:
    // 基本上就是原本II題目中多了最多交易K次的限制(多一個維度)
    int maxProfit(vector<int>& prices)
    {
        fill((int*)dp, (int*)dp + 100005 * 2 * 3, -0x3f3f3f3f);

        int n = prices.size();

        // 第一天什麼都沒做
        dp[0][0][0] = 0;
        // 第一天買股票
        dp[0][1][0] = -prices[0];

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= 2; ++j) // 操作次數
            {
                // 今天沒有股票，沒有賣股票
                dp[i][0][j] = dp[i - 1][0][j];
                // 今天沒有股票，有賣股票
                if (j > 0)
                    dp[i][0][j] = max(dp[i][0][j], dp[i - 1][1][j - 1] + prices[i]);
                // 今天有股票，沒有買股票
                dp[i][1][j] = dp[i - 1][1][j];
                // 今天有股票，有買股票
                dp[i][1][j] = max(dp[i][1][j], dp[i - 1][0][j] - prices[i]);
            }
        }

        return max({dp[n - 1][0][0], dp[n - 1][0][1], dp[n - 1][0][2]});
    }
};

int main()
{
    Solution S;
    vector<int> prices = {1, 2, 3, 4, 5};
    S.maxProfit(prices);

    return 0;
}