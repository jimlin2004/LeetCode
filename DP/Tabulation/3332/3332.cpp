#include <bits/stdc++.h>
using namespace std;

#define maxn 205
#define maxk 205

class Solution 
{
public:
    // 題目數值範圍看起來挺dp的，轉移式算簡單的
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) 
    {
        /*
            dp[u][j] -> 在經過j天後到city u可以獲得的最大獲利
            dp[u][j] = max {
                dp[i][j - 1] + stayScore[j - 1], // 留著
                dp[v][j - 1] + travelScore[v][u] // 從v走到u
            }
        */
        int dp[maxn][maxk];
        // 初始化
        memset(dp, 0, sizeof(dp));
        for (int T = 1; T <= k; ++T)
        {
            for (int u = 0; u < n; ++u)
            {
                dp[u][T] = dp[u][T - 1] + stayScore[T - 1][u];
                for (int v = 0; v < n; ++v)
                {
                    if (u == v)
                        continue;
                    dp[u][T] = max(dp[u][T], dp[v][T - 1] + travelScore[v][u]);
                }
            }
        }
        int res = 0;
        for (int u = 0; u < n; ++u)
        {
            res = max(res, dp[u][k]);
        }
        return res;
    }
};