#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        //簡單dp
        //dp[i][0] -> 以i為結尾且是+的最大交替和
        //dp[i][1] -> 以i為結尾且是-的最大交替和

        int n = nums.size();
        //初始化
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; ++i)
        {
            //dp[i][0]可選nums[i]自己當新的開頭 or 不選nums[i] -> dp[i - 1][0] or 選 -> dp[i - 1][1] + nums[i]
            dp[i][0] = max({(long long)nums[i], dp[i - 1][0], dp[i - 1][1] + nums[i]});
            //dp[i][1]可 不選nums[i] -> dp[i - 1][1] or 選 -> dp[i - 1][0] - nums[i]
            dp[i][1] = max({dp[i - 1][1], dp[i - 1][0] - nums[i]});
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
private:
    static const int maxn = 100005;
    long long dp[maxn][2];
};