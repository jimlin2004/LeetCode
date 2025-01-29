#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

class Solution 
{
public:
    const int dir[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    int m, n;

    int findMaxFish(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        int maxFish = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] != 0)
                {
                    maxFish = max(maxFish, bfs(grid, {j, i}));
                }
            }
        }
        return maxFish;
    }

    inline bool isValid(int x, int y)
    {
        return (0 <= x) && (x < n) && (0 <= y) && (y < m);
    }

    int bfs(vector<vector<int>>& grid, const Point& s)
    {
        int totalFish = 0;
        queue<Point> q;
        totalFish += grid[s.y][s.x];
        grid[s.y][s.x] = 0;
        q.push(s);
        while (!q.empty())
        {
            Point curr = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d)
            {
                int nx = curr.x + dir[d][0];
                int ny = curr.y + dir[d][1];
                if (isValid(nx, ny) && grid[ny][nx] != 0)
                {
                    q.push({nx, ny});
                    totalFish += grid[ny][nx];
                    grid[ny][nx] = 0;
                }
            }
        }
        return totalFish;
    }
};