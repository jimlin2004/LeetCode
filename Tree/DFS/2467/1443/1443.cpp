#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> G;

    int dfs(int u, int p, bool& pathHasApple, vector<bool>& hasApple)
    {
        int cost = 0;
        
        for (int v: G[u])
        {
            if (v == p)
                continue;
            bool currPathHas = false;
            int childCost = dfs(v, u, currPathHas, hasApple);
            pathHasApple |= currPathHas;
            cost += childCost + 2 * (currPathHas);
        }

        pathHasApple |= hasApple[u];

        return cost;
    }

    // dfs下去合成答案即可

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        G.assign(n + 5, {});

        for (auto& edge: edges)
        {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }

        bool curr = false;

        return dfs(0, -1, curr, hasApple);
    }
};