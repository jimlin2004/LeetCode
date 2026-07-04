#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        因為這一題的path是可以走重複邊、點的
        所以問題的性質變成如果這個edge與1有間接相連
        且因為一定有path能從1 -> n
        所以所有與1間接相連的edge都是可以選的最小權重候選
        因此用union find處理node是否與1相連即可(要的答案的edge與那個node相連)
    */

    int parent[100005];

    int findRoot(int x)
    {
        if (parent[x] < 0)
            return x;
        return parent[x] = findRoot(parent[x]);
    }

    bool Uni(int a, int b)
    {
        int r1 = findRoot(a);
        int r2 = findRoot(b);
        if (r1 == r2)
            return false;
        if (parent[r1] < parent[r2])
        {
            parent[r1] += parent[r2];
            parent[r2] = r1;
        }
        else
        {
            parent[r2] += parent[r1];
            parent[r1] = r2;
        }

        return true;
    }

    int minScore(int n, vector<vector<int>>& roads) 
    {
        memset(parent, -1, sizeof(parent));

        for (auto& edge: roads)
        {
            Uni(edge[0], edge[1]);
        }

        int res = 0x3f3f3f3f;
        int rootOf1 = findRoot(1);
        for (auto& edge: roads)
        {
            if (findRoot(edge[0]) == rootOf1 || findRoot(edge[1]) == rootOf1)
                res = min(res, edge[2]);
        }

        return res;
    }
};