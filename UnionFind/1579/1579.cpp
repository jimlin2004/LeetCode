#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> rootAlice;
    vector<int> rootBob;

    int findRoot(int x, vector<int>& root)
    {
        if (root[x] < 0)
            return x;
        return root[x] = findRoot(root[x], root);
    }

    bool canUni(int a, int b, vector<int>& root)
    {
        int r1 = findRoot(a, root);
        int r2 = findRoot(b, root);

        return (r1 != r2);
    }

    bool uni(int a, int b, vector<int>& root)
    {
        int r1 = findRoot(a, root);
        int r2 = findRoot(b, root);

        if (r1 == r2)
            return false;

        if (root[r1] < root[r2])
        {
            root[r1] += root[r2];
            root[r2] = r1;
        }
        else
        {
            root[r2] += root[r1];
            root[r1] = r2;
        }
        return true;
    }

    /*
        這題是類似greedy的思想
        方法是能用共用的就先用
        因為如果不用這個共用的邊
        則Alice與Bob會需要額外的各自一條邊去連接原本可以一條邊就連接的u、v
    */
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        int res = 0;

        rootAlice.assign(n + 5, -1);
        rootBob.assign(n + 5, -1);

        // 先用Type 3
        for (auto& edge: edges)
        {
            if (edge[0] == 3)
            {
                if (canUni(edge[1], edge[2], rootAlice) && canUni(edge[1], edge[2], rootBob))
                {
                    uni(edge[1], edge[2], rootAlice);
                    uni(edge[1], edge[2], rootBob);
                }
                else
                    ++res;
            }
        }

        // 分別使用各自的
        for (auto& edge: edges)
        {
            if (edge[0] == 1)
            {
                if (!uni(edge[1], edge[2], rootAlice))
                    ++res;
            }
            else if (edge[0] == 2)
            {
                if (!uni(edge[1], edge[2], rootBob))
                    ++res;
            }
        }

        // 檢查是否全連通
        for (int i = 2; i <= n; ++i)
        {
            // 如果有canUni -> 該圖有兩群 -> 不全連通
            if (canUni(1, i, rootAlice) || canUni(1, i, rootBob))
                return -1;
        }

        return res;
    }
};