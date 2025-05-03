#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

class Solution 
{
public:
    vector<vector<int>> G;
    int indeg[maxn];

    int cnt[maxn][30]; // 當前節點的每個路徑最大顏色數量

    // 用拓樸的概念，加上一點DAG的DP
    // 考慮v只會被u更新，所以用拓樸慢慢走過去後，更新cnt維護答案
    // O(V + E)
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        memset(cnt, 0, sizeof(cnt));

        int n = colors.size();
        G.assign(n + 5, vector<int>());

        for (auto& edge: edges)
        {
            if (edge[0] == edge[1]) // 有自環
                return -1;
            G[edge[0]].push_back(edge[1]);
            ++indeg[edge[1]];
        }

        int res = 0;
        
        queue<int> q;

        for (int u = 0; u < n; ++u)
        {
            if (indeg[u] == 0)
            {
                q.push(u);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ++cnt[u][colors[u] - 'a'];
            res = max(res, cnt[u][colors[u] - 'a']);
            for (int v: G[u])
            {
                --indeg[v];
                if (indeg[v] == 0)
                    q.push(v);
                // 更新v的cnt
                for (int i = 0; i < 30; ++i)
                {
                    cnt[v][i] = max(cnt[v][i], cnt[u][i]);
                }
            }
        }

        for (int u = 0; u < n; ++u)
        {
            if (indeg[u] != 0) // 有環
                return -1;
        }

        return res;
    }
};


int main()
{
    string colors = "hhqhuqhqff";
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{3,4},{3,5},{5,6},{2,7},{6,7},{7,8},{3,8},{5,8},{8,9},{3,9},{6,9}};
    Solution S;
    S.largestPathValue(colors, edges);
}