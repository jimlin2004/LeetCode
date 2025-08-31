#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 水題
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();

        // 大到小
        for (int k = 0; k < n; ++k)
        {
            vector<int> temp;

            for (int i = k, j = 0; i < n && j < n; ++i, ++j)
                temp.emplace_back(-grid[i][j]);
            
            // 用負數處理大到小
            sort(temp.begin(), temp.end());

            for (int i = k, j = 0; j < temp.size(); ++i, ++j)
                grid[i][j] = -temp[j];
        }

        // 小到大
        for (int k = 1; k < n; ++k)
        {
            vector<int> temp;

            for (int i = 0, j = k; i < n && j < n; ++i, ++j)
                temp.emplace_back(grid[i][j]);
            
            sort(temp.begin(), temp.end());

            for (int i = 0, j = k; i < temp.size(); ++i, ++j)
                grid[i][j] = temp[i];
        }

        return grid;
    }
};