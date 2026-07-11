#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deg[55];
    bool vis[55];

    vector<vector<int>> G;

    bool dfs(int u, int targetCompDeg, int& compNodeCnt)
    {
        vis[u] = true;
        ++compNodeCnt;
        bool ok = deg[u] == targetCompDeg;
        for (int v: G[u])
        {
            if (!vis[v])
            {
                if (!dfs(v, targetCompDeg, compNodeCnt))
                    ok = false;
            }
        }

        return ok;
    }

    // dfs + degree判一下就行了
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        G.assign(n + 5, {});
        memset(deg, 0, sizeof(deg));

        for (const auto& edge: edges)
        {
            ++deg[edge[0]];
            ++deg[edge[1]];
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }

        memset(vis, 0, sizeof(vis));

        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                int compNodeCnt = 0;
                if (dfs(i, deg[i], compNodeCnt))
                {
                    if (deg[i] == compNodeCnt - 1)
                    {
                        ++res;
                    }
                }
            }
        }

        return res;
    }
};