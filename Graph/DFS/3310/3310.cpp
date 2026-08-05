#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        題意是指由k能走到的點都是suspicious
        但如果這些點能被不是suspicious的點走到
        那他們又不是

        所以就是從k出發找所有suspicious的點
        然後再看有沒有人可以走到這些點

        還有沒有辦法走到的邏輯用indegree判斷
    */
    vector<vector<int>> G;
    vector<int> indegree;
    vector<int> isSuspicious;

    void dfs(int u)
    {
        isSuspicious[u] = true;

        for (int v: G[u])
        {
            --indegree[v];
            if (!isSuspicious[v])
                dfs(v);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
    {
        G.assign(n + 5, {});
        indegree.assign(n + 5, 0);
        isSuspicious.assign(n + 5, false);

        for (auto& edge: invocations)
        {
            G[edge[0]].emplace_back(edge[1]);
            ++indegree[edge[1]];
        }

        dfs(k);

        bool canRemove = true;
        for (int u = 0; u < n; ++u)
        {
            if (isSuspicious[u] && indegree[u] > 0)
            {
                canRemove = false;
                break;
            }
        }

        vector<int> res;
        for (int u = 0; u < n; ++u)
        {
            if (!canRemove)
                res.emplace_back(u);
            else if (!isSuspicious[u])
                res.emplace_back(u);
        }

        return res;
    }
};