#include <bits/stdc++.h>
using namespace std;

#define maxn 205

class Solution 
{
public:

    int cost[maxn][maxn]; // i ~ j不替換的最小cost
    int dp[maxn][maxn]; // dp[i][k] -> 到第i個時，用了k個操作

    int minSpaceWastedKResizing(vector<int>& nums, int k) 
    {
        int n = nums.size();

        memset(dp, 0x3f, sizeof(dp));

        // O(n ^ 2)計算i ~ j的最小成本
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            int maxVal = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                maxVal = max(maxVal, nums[j]);
                cost[i][j] = (maxVal * (j - i + 1)) - sum;
            }
            dp[i][0] = cost[0][i];
        }

        // O(n ^ 2 * k)去枚舉所有的組合
        for (int i = 0; i < n; ++i)
        {
            for (int c = 1; c <= k; ++c)
            {
                for (int j = i; j >= 0; --j) // j從i開始，才能繼承答案到k，因為可能不需要操作到k就能最小
                {
                    dp[i][c] = min(dp[i][c], dp[j - 1][c - 1] + cost[j][i]);
                }
            }
        }

        return dp[n - 1][k];
    }
};


int main()
{
    Solution S;
    vector<int> nums = {10,20,15,30,20};
    int k = 2;
    S.minSpaceWastedKResizing(nums, k);
}