#include <bits/stdc++.h>
using namespace std;

//dp[i][0] -> 第i天時沒有股票在手上的最佳利益
//dp[i][1] -> 第i天時有股票在手上的最佳利益
//討論轉移式:
//第i天沒有股票->第i - 1天沒有股票且今天什麼事都不做或第i - 1天有股票今天賣掉
//第i天有股票  ->第i - 1天有股票且今天什麼事都不做或第i - 1天沒有股票今天買了
//<注> 可以dp滾動陣列

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int dp[50005][2];
        memset(dp, 0, sizeof(dp));
        //沒有股票，第一天肯定是0
        dp[0][0] = 0;
        //考慮第一天有買入的情況
        dp[0][1] = -prices[0];
        int n = prices.size();
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};