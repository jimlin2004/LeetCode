#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> infected;

    vector<vector<int>> G;
    // 移除該子樹可以拯救多少節點
    vector<int> saved;

    int steps = 0;
    vector<int> dfn;
    vector<int> low;

    // Tarjan
    int dfs(int u, int p)
    {
        dfn[u] = low[u] = steps++;

        // 這個節點以下的子樹中是否有人已經中毒
        bool hasInfected = infected[u];
        int savedCnt = (infected[u] != 1);
        for (int v: G[u])
        {
            if (dfn[v] == -1)
            {
                int cnt = dfs(v, u);
                // 這個子樹有毒
                if (cnt == 0)
                    hasInfected = true;
                else
                    savedCnt += cnt;
                
                // 這子樹一定要經過u
                if (dfn[u] <= low[v])
                {
                    saved[u] += cnt;
                }

                low[u] = min(low[u], low[v]);
            }
            else if (v != p) // backward edge
                low[u] = min(low[u], dfn[v]);
        }

        return (hasInfected) ? 0 : savedCnt;
    }

    /*
        看到題目會直覺的找橋接點分元件
        所以就是用Tarjan找到所有點移除時能夠拯救多少節點
        那些橋接點移除之後被斷開的元件如果沒有中毒的點
        該元件就安全了
        反之則還是沒救
        所以就是dfs找元件的同時維護一下該元件是否能被拯救
        同時又能救多少節點即可
    */
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial)
    {
        int n = graph.size();
        infected.assign(n + 5, 0);
        G.assign(n + 5, {});
        saved.assign(n + 5, 0);
        dfn.assign(n + 5, -1);
        low.assign(n + 5, 0x3f3f3f3f);

        for (int u = 0; u < n; ++u)
        {
            for (int v = 0; v < n; ++v)
            {
                if (u == v)
                    continue;
                if (graph[u][v])
                    G[u].emplace_back(v);
            }
        }

        for (int u: initial)
            infected[u] = 1;
        
        int maxRes = 0;
        int res = 0x3f3f3f3f;

        for (int u: initial)
        {
            if (dfn[u] == -1)
                dfs(u, -1);
            
            if (saved[u] > maxRes)
            {
                maxRes = saved[u];
                res = u;
            }
            else if (saved[u] == maxRes)
                res = min(res, u);
        }

        return res;
    }
};


int main()
{
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    vector<int> init = {0, 1};
    Solution S;
    S.minMalwareSpread(graph, init);
    return 0;
}