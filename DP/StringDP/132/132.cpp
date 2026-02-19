#include <bits/stdc++.h>
using namespace std;


class Solution
{
private:
    bool isP[2005][2005];
    int dp[2005][2005];
public:
    // 經典迴文表 + 往迴找分段最小成本 O(n ^ 2)
    int minCut(string s)
    {
        int n = s.size();

        memset(isP, 0, sizeof(isP));
        memset(dp, 0x3f, sizeof(dp));

        for (int l = 1; l <= n; ++l)
        {
            for (int i = 0, j = i + l - 1; j < n; ++i, ++j)
            {
                if (l == 1)
                    isP[i][j] = true;
                else if (l == 2)
                    isP[i][j] = (s[i] == s[j]);
                else
                    isP[i][j] = (isP[i + 1][j - 1] && (s[i] == s[j]));
            }
        }

        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i <= j; ++i)
            {
                if (isP[i][j])
                {
                    int prevCost = (i - 1 >= 0) ? dp[0][i - 1] : 0;
                    dp[0][j] = min(dp[0][j], prevCost + 1);
                }
            }
        }

        // -1是因為問cut，而不是分成幾段
        return dp[0][n - 1] - 1;
    }
};

int main()
{
    Solution S;
    S.minCut("aab");

    return 0;
}