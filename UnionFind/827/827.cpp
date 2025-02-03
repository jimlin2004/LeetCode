#include <bits/stdc++.h>
using namespace std;

#define maxn 505

class Solution 
{
public:
    int parent[maxn * maxn];
    int n;

    inline int to1D(int x, int y)
    {
        return n * y + x;
    }

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

    inline bool isValid(int x, int y)
    {
        return (0 <= x) && (x < n) && (0 <= y) && (y < n);
    }

    // 2D並查集暴力連起來搜最大答案就行了
    int largestIsland(vector<vector<int>>& grid) 
    {
        const int dir[4][2] = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };

        memset(parent, -1, sizeof(parent));
        n = grid.size();
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                    continue;
                for (int d = 0; d < 4; ++d)
                {
                    int nx = j + dir[d][0];
                    int ny = i + dir[d][1];
                    if (isValid(nx, ny) && (grid[ny][nx] == 1))
                    {
                        uni(to1D(j, i), to1D(nx, ny));
                    }
                }
            }
        }

        int res = 0;
        int neighbor[10];

        int hasWater = false;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    continue;
                hasWater = true;
                int cnt = 0;
                for (int d = 0; d < 4; ++d)
                {
                    int nx = j + dir[d][0];
                    int ny = i + dir[d][1];
                    if (isValid(nx, ny) && (grid[ny][nx] == 1))
                    {
                        neighbor[cnt] = findRoot(to1D(nx, ny));
                        ++cnt;
                    }
                }
                sort(neighbor, neighbor + cnt);
                cnt = unique(neighbor, neighbor + cnt) - neighbor;
                int neighborIslandSum = 0;
                for (int island = 0; island < cnt; ++island)
                    neighborIslandSum += -parent[neighbor[island]];
                
                res = max(res, neighborIslandSum + 1);
            }
        }

        // 整個都是島
        if (!hasWater)
            res = n * n;

        return res;
    }
};