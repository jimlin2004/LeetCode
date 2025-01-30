#include <bits/stdc++.h>
using namespace std;

#define maxn 505

class Solution 
{
public:
    // 參考官解
    // 首先判斷Group的存在性，只有整個圖能夠變成Bipartite才可能分group
    // Bipartite可以用coloring的方法處理
    // 若存在，之後只需要用BFS找每個component最多能有幾個layer
    // 這一步需要對所有的點做bfs，之後每個component從哪個node出發有最大的layer
    // 即找到bfs tree有最大深度的，最大深度即為該component的最多group數
    // 另外，圖可能不連接
    // 因此所有不連接的圖能分多少Group都要加起來

    vector<vector<int>> G;

    int magnificentSets(int n, vector<vector<int>>& edges) 
    {
        G.assign(n + 5, vector<int>());
        for (auto& edge: edges)
        {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }

        int color[maxn];
        vector<vector<int>> components;
        memset(color, 0, sizeof(color));
        for (int u = 1; u <= n; ++u)
        {
            if (color[u] == 0)
            {
                components.emplace_back();
                color[u] = 1;
                if (!isBipartite(u, color, components.back()))
                {
                    // 不是二分圖，不可能分group
                    return -1;
                }
            }
        }

        int res = 0;
        for (auto& component: components)
        {
            int maxGroup = 0;
            for (int u: component)
            {
                maxGroup = max(maxGroup, getMaxDepth(u));
            }
            res += maxGroup;
        }
        return res;
    }

    // coloring檢查
    bool isBipartite(int u, int color[], vector<int>& component)
    {
        component.emplace_back(u);
        for (int v: G[u])
        {
            if (color[v] == 0)
            {
                color[v] = ~color[u];
                if (!isBipartite(v, color, component))
                    return false;
            }
            if (color[u] == color[v])
                return false;
        }
        return true;
    }

    // bfs找bfs tree的深度
    int getMaxDepth(int s)
    {
        static bool vis[maxn];
        memset(vis, 0, sizeof(vis));
        int maxDepth = 0;
        queue<int> q;
        q.push(s);
        vis[s] = true;
        while (!q.empty())
        {
            ++maxDepth;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                int u = q.front();
                q.pop();
                for (int v: G[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return maxDepth;
    }
};