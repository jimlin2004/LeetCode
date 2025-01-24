#include <bits/stdc++.h>
using namespace std;

#define maxn 10005

class Solution 
{
public:
    bool isSafe[maxn];
    bool vis[maxn];

    // dfs搜一遍就過了(每個節點當起頭做dfs看看)
    // 用isSafe快速處理搜過的節點
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        memset(isSafe, 0, sizeof(isSafe));
        memset(vis, 0, sizeof(vis));

        vector<int> res;
        int n = graph.size();
        for (int u = 0; u < n; ++u)
        {
            dfs(u, graph);
            if (isSafe[u])
                res.emplace_back(u);
        }
        return res;
    }

    void dfs(int u, vector<vector<int>>& G)
    {
        if (vis[u])
            return;
        vis[u] = true;
        if (G[u].empty())
        {
            isSafe[u] = true;
            return;
        }
        for (int v: G[u])
        {
            dfs(v, G);
            if (!isSafe[v])
            {
                isSafe[u] = false;
                return;
            }
        }
        isSafe[u] = true;
    }
};