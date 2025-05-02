#include <bits/stdc++.h>
using namespace std;


#define maxn 30005

class Solution 
{
public:
    // dp[i][0] -> 到第i天時，沒有股票
    // dp[i][1] -> 到第i天時，有股票
    // 的最大利潤
    int dp[maxn][2];

    // dp[i]只需要考慮dp[i - 1]，因為是一天天過得
    // 所以只要枚舉什麼都不做以及買或賣股票的所有可能就能得到答案
    int maxProfit(vector<int>& prices) 
    {
        memset(dp, 0, sizeof(dp));

        int n = prices.size();

        // 什麼都沒做
        dp[0][0] = 0;
        // 第0天買股票
        dp[0][1] = -prices[0];
        
        for (int i = 1; i < n; ++i)
        {
            // 第i天時可以什麼都不做也可以賣掉股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 第i天時可以甚麼都不做也可以買入股票
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        // 第n - 1天時沒理由不將股票賣掉
        return dp[n - 1][0];
    }
};


int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution S;
    S.maxProfit(prices);

    return 0;
}