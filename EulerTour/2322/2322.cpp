#include <bits/stdc++.h>
using namespace std;

/*
    還算簡單題
    由於是tree
    所以只要拿掉兩個邊一定會變成3個component
    所以先用dfs將樹壓平後順便處理每個子樹的xor結果
    之後枚舉u, v兩個新component的root
    然後分別用dfn的性質討論u、v的父子關係
    維護最好的答案即可
*/

class Solution 
{
public:
    vector<vector<int>> G;
    vector<int> inDFN; // 進來的時間
    vector<int> outDFN; // 出去的時間
    vector<int> xorDP; // 以u為root的subtree計算xor的結果 -> xorDP[u]
    int dfn = 0;

    // 樹壓平 + 處理子樹xor結果
    void dfs(int u, int p, vector<int>& nums)
    {
        xorDP[u] = nums[u];

        inDFN[u] = dfn++;
        for (int v: G[u])
        {
            if (v == p)
                continue;
            dfs(v, u, nums);

            xorDP[u] ^= xorDP[v];
        }

        outDFN[u] = dfn;
    }

    // 計算答案
    inline int cal(int p1, int p2, int p3)
    {
        return max({p1, p2, p3}) - min({p1, p2, p3});
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n = nums.size();

        G.assign(n + 5, {});
        inDFN.assign(n + 5, 0);
        outDFN.assign(n + 5, 0);
        xorDP.assign(n + 5, 0);

        for (auto& edge: edges)
        {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }

        dfs(0, -1, nums);

        int res = 0x3f3f3f3f;

        // 枚舉兩個邊
        for (int u = 1; u < n; ++u)
        {
            for (int v = 1; v < n; ++v)
            {
                if (u == v)
                    continue;

                // 如果v在u的子樹
                if (inDFN[u] < inDFN[v] && inDFN[v] < outDFN[u])
                {
                    int firstPart = xorDP[0] ^ xorDP[u];
                    int secondPart = xorDP[u] ^ xorDP[v];
                    int thirdPart = xorDP[v];

                    res = min(res, cal(firstPart, secondPart, thirdPart));
                }
                // 如果u在v的子樹
                else if (inDFN[v] < inDFN[u] && inDFN[u] < outDFN[v])
                {
                    int firstPart = xorDP[0] ^ xorDP[v];
                    int secondPart = xorDP[v] ^ xorDP[u];
                    int thirdPart = xorDP[u];

                    res = min(res, cal(firstPart, secondPart, thirdPart));
                }
                else // u跟v分屬不同子樹
                {
                    int firstPart = xorDP[0] ^ xorDP[u] ^ xorDP[v];
                    int secondPart = xorDP[u];
                    int thirdPart = xorDP[v];

                    res = min(res, cal(firstPart, secondPart, thirdPart));
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution S;
    vector<int> nums = {1,5,5,4,11};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};

    S.minimumScore(nums, edges);

    return 0;
}