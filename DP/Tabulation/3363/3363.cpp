#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int dp[1005][1005];

    /*
        因為限制三個人的步數只能是n - 1步
        所以很明顯左上角的child因為位置的關係
        因此他只有斜對角的走法
        同時對於右上角的child只能保持在上三角走訪
        左下角的child只能在下三角走訪
        所以除了左上角的答案就是斜對角加起來
        另外兩個child用dp簡單推一下即可

        O(n ^ 2)
        另外下方dp用往前加的做法
    */
    int maxCollectedFruits(vector<vector<int>>& fruits)
    {
        int n = fruits.size();

        memset(dp, 0, sizeof(dp));

        // 右上角的child
        int prevLen = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            int currLen = 0;
            for (int j = n - 1 - prevLen; j < n; ++j)
            {
                if (i >= j)
                    continue;
                dp[i][j] += fruits[i][j];
                ++currLen;

                // 上三角滿足i < j

                // 往左下
                if (i + 1 < j - 1)
                    dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j]);
                // 往下
                if (i + 1 < j)
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                // 往右下
                if (j + 1 < n && i + 1 < j + 1)
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            }
            prevLen = currLen;
        }

        // 左下角的child
        prevLen = 0;
        for (int j = 0; j < n - 1; ++j)
        {
            int currLen = 0;
            for (int i = n - 1 - prevLen; i < n; ++i)
            {
                if (j >= i)
                    continue;
                dp[i][j] += fruits[i][j];
                ++currLen;

                // 下三角滿足i > j

                // 往右上
                if (i - 1 > j + 1)
                    dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j]);
                // 往右
                if (i > j + 1)
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
                // 往右下
                if (i + 1 < n && i + 1 > j + 1)
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            }
            prevLen = currLen;
        }

        // 左上角的child
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] += fruits[i][i];
            dp[i + 1][i + 1] = dp[i][i];
        }

        return dp[n - 2][n - 1] + dp[n - 1][n - 1] + dp[n - 1][n - 2];
    }
};


int main()
{
    vector<vector<int>> F = {{1,2,3,4},{5,6,8,7},{9,10,11,12},{13,14,15,16}};
    Solution S;
    S.maxCollectedFruits(F);

    return 0;
}