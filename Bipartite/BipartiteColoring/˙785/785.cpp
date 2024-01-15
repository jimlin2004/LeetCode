#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        memset(this->color, 0, sizeof(this->color));
        bool currentColor = false;
        for (int i = 0; i < graph.size(); ++i)
        {
            if (this->color[i] == 0)
            {
                if (!dfs(graph, i, currentColor))
                    return false;
            }
        }
        return true;
    }

    int getColor(bool color)
    {
        return (color) ? 1 : -1;
    }

    bool dfs(vector<vector<int>>& G, int u, bool currColor)
    {
        if (this->color[u] == 0)
        {
            this->color[u] = this->getColor(currColor);
        }
        for (int v: G[u])
        {
            if (this->color[v] == 0)
            {
                if (!this->dfs(G, v, !currColor))
                    return false;
            }
            if (this->color[u] == this->color[v])
                return false;
        }
        return true;
    }
private:
    int color[105];
};