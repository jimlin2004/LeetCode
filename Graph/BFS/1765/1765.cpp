#include <bits/stdc++.h>
using namespace std;

struct Cell
{
    int i, j;
};

class Solution 
{
public:
    int m, n;
    int dir[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    // 簡單題
    // 就水是開頭
    // 跑bfs最早到的距離就是能填的最大height
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        m = isWater.size();
        n = isWater[0].size();
        vector<vector<int>> height;
        height.assign(m, vector<int>(n));
        bfs(height, isWater);
        return height;
    }

    inline bool isValid(int i, int j)
    {
        return (0 <= i) && (i < m) && (0 <= j) && (j < n);
    }

    void bfs(vector<vector<int>>& height, vector<vector<int>>& isWater)
    {
        bool vis[1005][1005];
        queue<Cell> q;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isWater[i][j])
                {
                    vis[i][j] = true;
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            Cell curr = q.front();
            int h = height[curr.i][curr.j];
            q.pop();
            for (int d = 0; d < 4; ++d)
            {
                int ni = curr.i + dir[d][1];
                int nj = curr.j + dir[d][0];
                if (isValid(ni, nj) && !vis[ni][nj])
                {
                    vis[ni][nj] = true;
                    height[ni][nj] = h + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
};