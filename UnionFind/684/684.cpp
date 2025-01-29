#include <bits/stdc++.h>
using namespace std;

#define maxn 1005

class Solution 
{
public:
    int parent[maxn];

    int findRoot(int x)
    {
        if (parent[x] < 0)
            return x;
        return parent[x] = findRoot(parent[x]);
    }

    bool uni(int a, int b)
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

    // 考基本並查集用法，建樹找會造成環的邊
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        memset(parent, -1, sizeof(parent));
        for (auto& edge: edges)
        {
            if (!uni(edge[0], edge[1]))
            {
                return edge;
            }
        }
        // 理論上不會到這裡
        return vector<int>();
    }
};