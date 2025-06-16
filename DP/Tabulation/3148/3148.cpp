#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maxScore(vector<vector<int>>& grid) 
    {
        int dp[1005][1005];
        memset(dp, 0x3f, sizeof(dp));
        int A[1005][1005]; // 將grid往右下一格

        int res = -0x3f3f3f3f;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                A[i][j] = grid[i - 1][j - 1];
            }
        }

        // 因為從c1 ~ ck的最好path
        // res = (c2 - c1) + (c3 - c2) + (c4 - c3) + ... + (ck - ck - 1) = ck - c1
        // 所以只要能知道ck的左上角最小值c1，就能找到答案ck - c1

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                res = max(res, A[i][j] - min(dp[i - 1][j], dp[i][j - 1]));
                dp[i][j] = min({A[i][j], dp[i - 1][j], dp[i][j - 1]});
            }
        }

        return res;
    }
};