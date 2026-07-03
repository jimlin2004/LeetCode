#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

struct Edge
{
    int u, v;
    int w;
};

class Solution
{
public:
    vector<vector<Edge>> invG;

    bool vis[maxn];

    void dfs(int u, int maxW, int& cnt)
    {
        ++cnt;
        vis[u] = true;

        for (Edge& edge: invG[u])
        {
            if (edge.w > maxW)
                continue;
            if (!vis[edge.v])
                dfs(edge.v, maxW, cnt);
        }
    }

    /*
        一眼對答案二分搜的題目
        首先要求所有的節點要能到0
        所以改成反向圖之後看0能不能到所有節點
        但是答案的threshold是個陷阱
        因為搜尋的時候是從0出發的一個dfs tree
        從dfs tree來看一個節點可能有多的子樹的邊出去
        但是由於我們是在invG上做的dfs tree
        所以換回原圖時dfs tree的邊是反過來的(從leaf到root)
        此時可以發現到每個點都只需要一個邊就能直接/間接走到0
        所以threshold根本就不用理他
    */

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold)
    {
        invG.assign(n + 5, {});

        for (auto& edge: edges)
            invG[edge[1]].emplace_back(Edge{edge[1], edge[0], edge[2]});
        
        // r是可以的下界
        // l是不可以的上界
        int l = 0, r = 0x3f3f3f3f;
        int reachCnt = 0;

        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;

            reachCnt = 0;

            memset(vis, 0, sizeof(vis));
            dfs(0, mid, reachCnt);

            if (reachCnt == n)
                r = mid;
            else
                l = mid;
        }

        return (l + 1 >= 0x3f3f3f3f) ? -1 : l + 1; // l + 1才可以的下界
    }
};


int main()
{
    Solution S;
    vector<vector<int>> edges = {{1,0,1},{2,0,2},{3,0,1},{4,3,1},{2,1,1}};
    S.minMaxWeight(5, edges, 2);

    return 0;
}