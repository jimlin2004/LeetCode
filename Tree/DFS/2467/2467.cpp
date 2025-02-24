#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 有趣的題目
    // 這題是tree，所以任意兩點路徑唯一
    // 解法是利用dfn，分別做alice與bob的dfs
    // 由於bob的路徑只會是bob -> 0
    // 先利用dfs找出bob到0路徑的dfn
    // 之後alice出發用dfs找所有可能的路徑，同時考慮bob的dfn要做一些判斷計算
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n = edges.size();
        vector<vector<int>> G;
        G.assign(n + 5, vector<int>());
        for (vector<int>& edge: edges)
        {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }

        vector<int> bobDFN(n + 5, -1);
        getBobDFN(bob, -1, 0, bobDFN, G);

        int maxScore = -0x3f3f3f3f;
        dfs(0, -1, 0, 0, maxScore, bobDFN, G, amount);

        return maxScore;
    }

    bool getBobDFN(int u, int p, int t, vector<int>& dfn, vector<vector<int>>& G)
    {
        dfn[u] = t;
        if (u == 0)
            return true;
        for (int v: G[u])
        {
            if (v == p)
                continue;
            if (getBobDFN(v, u, t + 1, dfn, G))
                return true;
            else
                dfn[v] = -1; // v不在Bob往0的路徑上
        }
        return false;
    }

    void dfs(int u, int p, int t, int currScore, int& maxScore,vector<int>& bobDFN, vector<vector<int>>& G, vector<int>& amount)
    {
        if (bobDFN[u] == -1 || t < bobDFN[u]) // bob沒走過或還沒到
            currScore += amount[u];
        else if (t > bobDFN[u]) // bob已經過去了
            currScore += 0;
        else if (t == bobDFN[u]) // alice與bob一起到
            currScore += amount[u] / 2;
        
        if (G[u].size() == 1 && u != 0) // 如果到了leaf，要特別判0，避免0也是leaf，答案會算錯
        {
            maxScore = max(maxScore, currScore);
            return;
        }
        
        for (int v: G[u])
        {
            if (v != p)
            {
                dfs(v, u, t + 1, currScore, maxScore, bobDFN, G, amount);
            }
        }
    }
};


int main()
{
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    int bob = 3;
    vector<int> amount = {-2,4,2,-4,6};
    Solution S;
    S.mostProfitablePath(edges, bob, amount);
    return 0;
}