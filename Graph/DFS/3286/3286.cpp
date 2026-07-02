#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // vis[i][j][health]
    bool vis[55][55][105];

    int m, n;

    int dir[4][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    inline bool isValid(int i, int j)
    {
        return (i >= 0) && (i < m) && (j >= 0) && (j < n);
    }

    bool dfs(int i, int j, const vector<vector<int>>& grid, int health)
    {
        if (health == 0)
            return false;
        
        if (i == m - 1 && j == n - 1)
            return true;
        
        vis[i][j][health] = true;

        for (int d = 0; d < 4; ++d)
        {
            int ni = i + dir[d][1];
            int nj = j + dir[d][0];

            if (isValid(ni, nj))
            {
                int isSafe = grid[ni][nj];
                if (!vis[ni][nj][health - isSafe])
                {
                    if (dfs(ni, nj, grid, health - isSafe))
                        return true;
                }
            }
        }

        return false;
    }

    // 簡單題，就只是多一個health的dfs而已
    // 其實正解可以用0/1 bfs
    bool findSafeWalk(vector<vector<int>>& grid, int health)
    {
        memset(vis, 0, sizeof(vis));

        m = grid.size();
        n = grid[0].size();

        // 第一格的safe記得要算
        return dfs(0, 0, grid, health - grid[0][0]);
    }
};