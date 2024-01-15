#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        dp[0] = cost[0];
        dp[1] = cost[1];
        int len = cost.size();
        for (int i = 2; i < len; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        return min(dp[len - 1], dp[len - 2]);
    }
private:
    int dp[1001];
};