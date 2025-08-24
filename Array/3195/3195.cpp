#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 水題
    // 找到x1 x2 y1 y2結束
    int minimumArea(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int x1 = 0x3f3f3f3f, x2 = -1;
        int y1 = 0x3f3f3f3f, y2 = -1;


        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    y1 = min(y1, i);
                    y2 = max(y2, i);
                    x1 = min(x1, j);
                    x2 = max(x2, j);
                }
            }            
        }

        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};