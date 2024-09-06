#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
public:
    // min-max解法
    // 其實這題因為Alice先拿，先手必勝，答案一定是true
    bool stoneGame(vector<int>& piles)
    {
        memset(dp, 0, sizeof(dp));
        int total = 0;
        for (int i = 0; i < piles.size(); ++i)
        {
            dp[i][i] = piles[i];
            total += piles[i];
        }
        for (int l = 2; l <= piles.size(); ++l)
        {
            for (int i = 0, j = i + l - 1; j < piles.size(); ++i, ++j)
            {
                if (l == 2)
                {
                    dp[i][j] = max(piles[i], piles[j]);
                }
                else
                {
                    int case1 = piles[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                    int case2 = piles[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
                    dp[i][j] = max(case1, case2);
                }
            }
        }
        return dp[0][piles.size() - 1] > total / 2;
    }
private:
    // dp[i][j] -> i ~ j全部玩完最大alice可得的分數
    int dp[505][505];
};