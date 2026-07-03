#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
    long long w;
};

class Solution
{
public:
    /*
        要求在DAG上最大的最小權重，path cost <= k

        有想到要用DAG DP
        但沒想到要用二分搜搜答案
        同時檢查是否存在路徑時可以用簡單DAG DP處理O(V + E)

        想到二分搜基本上就是簡單題了
    */

    vector<vector<Edge>> G;

    // 不能只使用dp判斷有沒有走過，否則容易發生一個node根本走不到T但會一直重複走的情況
    // dp用
    bool vis[50005];
    // dp[u] -> u 到 終點的最小總cost
    long long dp[50005];

    long long dfs(int u, const long long maxCost, const int T)
    {
        if (u == T)
        {
            vis[u] = true;
            dp[u] = 0;
            return dp[u];
        }

        if (vis[u])
            return dp[u];

        vis[u] = true;

        for (Edge& edge: G[u])
        {
            // 只使用 >= maxCost的邊
            if (edge.w < maxCost)
                continue;
            // 先下去求答案
            dfs(edge.v, maxCost, T);

            // 求最小到T的總cost
            dp[u] = min(dp[u], dp[edge.v] + edge.w);
        }

        return dp[u];
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k)
    {
        int n = online.size();
        G.assign(n + 5, {});

        for (auto& edge: edges)
        {
            if (!online[edge[0]] || !online[edge[1]])
                continue;
            G[edge[0]].emplace_back(Edge{edge[0], edge[1], edge[2]});
        }

        long long l = -1, r = k + 1;

        while (l + 1 < r)
        {
            long long mid = l + ((r - l) >> 1);
            memset(vis, 0, sizeof(vis));
            memset(dp, 0x3f, sizeof(dp));

            // vis[n - 1]代表有path可以到終點
            if (dfs(0, mid, n - 1) <= k && vis[n - 1])
                l = mid;
            else
                r = mid;
        }

        return l;
    }
};