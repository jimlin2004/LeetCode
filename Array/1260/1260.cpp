#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    inline int to1D(int i, int j, int m, int n)
    {
        return i * n + j;
    }

    inline pair<int, int> to2D(int i, int m, int n)
    {
        return make_pair(i / n, i % n);
    }

    // 簡單index操作
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res(grid);

        int len_1D = m * n;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int idx_1D = to1D(i, j, m, n);
                int newIdx_1D = (idx_1D + k) % len_1D;
                pair<int, int> new2DIdx = to2D(newIdx_1D, m, n);
                res[new2DIdx.first][new2DIdx.second] = grid[i][j];
            }
        }

        return res;
    }
};