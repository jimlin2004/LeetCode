#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        經典dp，拿deque頭尾的看最後誰分數最大
        做法是dp[i][j]是最大淨收益
        所以當面對一個區間[i ~ j]的時候
        可以拿nums[i]，這時候對手就會獲得dp[i + 1][j]的淨收益
        也可以拿nums[j]，這時候對手就會獲得dp[i][j - 1]的淨收益
        (因為都夠聰明，使得每個區間[i ~ j]的玩下去會有一樣的流程與結果)
        因此dp轉移式就是
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
        也就是我賺的 - 對手賺的淨收益

        最後檢查dp[0][n - 1]是不是 >= 0就知道是否先手勝
    */
    bool predictTheWinner(vector<int>& nums)
    {
        int dp[25][25];
        memset(dp, 0, sizeof(dp));

        int n = nums.size();

        // 只有一個數字時，淨收益就是拿走那個數字
        for (int i = 0; i < n; ++i)
            dp[i][i] = nums[i];
        
        // dp (算是區間dp)
        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i + len <= n; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};