#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &grid, int m, int n, int i, int j,int& count)
    {
        grid[i][j] = 0;
        count++;
        
        int dir[5] = {-1, 0, 1, 0, -1};
        for(int d = 0; d < 4; d++)
        {
            int x = i + dir[d];
            int y = j + dir[d+1];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
            {
                dfs(grid,m,n,x,y,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        int m = grid.size();
        int n = grid[0].size();
        if(m == 1 && n == 1)
        {
            return grid[0][0] == 1 ? 1 : 0;
        }
        int maxArea = 0;
        int count = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    count =0;
                    dfs(grid, m, n, i, j, count);
                    maxArea = max(count, maxArea);
                }
            }
        }
        return maxArea;
    }
};