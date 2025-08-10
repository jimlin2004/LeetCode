#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<bool> vis;
    vector<vector<int>> G;

    vector<vector<int>> components;

    void dfs(int u, vector<int>& component)
    {
        vis[u] = true;

        for (int v: G[u])
        {
            if (!vis[v])
                dfs(v, component);
        }

        component.emplace_back(u);
    }

    // 單純dfs算元件數即可
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        vis.assign(n + 5, false);
        G.assign(n + 5, {});

        for (auto& edge: edges)
        {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }

        for (int u = 0; u < n; ++u)
        {
            if (!vis[u])
            {
                vector<int> component;
                dfs(u, component);
                components.emplace_back(component);
            }
        }

        long long res = 0;

        for (int i = 0; i < components.size(); ++i)
        {
            res += (long long)components[i].size() * (n - components[i].size());
        }
    
        return res / 2; // 上面算法會來回算兩次
    }
};