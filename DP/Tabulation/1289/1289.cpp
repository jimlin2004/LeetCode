#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                    dp[i][j] = grid[i][j];
                else if (j == 0)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + grid[i][j];
                else if (j == n - 1)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + grid[i][j];
                else
                    dp[i][j]
            }
        }
    }
private:
    int dp[201][201];
};