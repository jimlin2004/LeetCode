#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int dp[305][15]; // dp[i][d] -> 討論到第i個工作，分d天做完的最小成本


    /*
        算簡單的dp
        定義dp後
        用暴搜找第i個工作要當作分段的最後一個時，往回找最好的上一個切點
        O(n * n * d)
    */
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        memset(dp, 0x3f, sizeof(dp));

        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        dp[0][1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][1] = max(dp[i - 1][1], jobDifficulty[i - 1]);
        }

        for (int j = 2; j <= d; ++j)
        {
            for (int i = 1; i <= n; ++i)
            {
                int mostDiff = jobDifficulty[i - 1]; // 先討論今天的工作難度
                for (int k = i - 1; k >= 1; --k)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + mostDiff);
                    mostDiff = max(mostDiff, jobDifficulty[k - 1]); // 維護更新最大的工作
                }
            }
        }
        return (dp[n][d] == 0x3f3f3f3f) ? -1 : dp[n][d];
    }
};


int main()
{
    vector<int> diff = {6, 5, 4, 3, 2, 1};
    Solution S;
    S.minDifficulty(diff, 2);

    return 0;
}