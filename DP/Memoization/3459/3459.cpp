#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    /*
        dp[i][j][dir][hasTurn] = max len
    */
    int dp[505][505][4][2];
    int m, n;
    // dir對應{i, j}的變化
    int dir[4][2] = {
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
    };

    inline bool isValid(int i, int j)
    {
        return (i >= 0) && (i < m) && (j >= 0) && (j < n);
    }

    int dfs(int i, int j, int d, int hasTurn, int target, vector<vector<int>>& grid)
    {
        if (!isValid(i, j) || (grid[i][j] != target))
            return 0;
        
        if (dp[i][j][d][hasTurn] != -1)
            return dp[i][j][d][hasTurn];

        // 2- target是因為不斷 2, 0, 2, 0, 2, 0, ...
        int maxLen = dfs(i + dir[d][0], j + dir[d][1], d, hasTurn, 2 - target, grid);

        if (hasTurn == 0)
        {
            int nextD = (d + 1) % 4;
            maxLen = max(maxLen, dfs(i + dir[nextD][0], j + dir[nextD][1], nextD, 1, 2 - target, grid));
        }

        dp[i][j][d][hasTurn] = maxLen + 1;

        return dp[i][j][d][hasTurn];
    }

    /*
        dp題
        用dfs(i, j, d, hasTurn)去搜尋
        以(i, j)為起始 方向為d 有沒有轉向過hasTurn 的最大長度
        由於hasTurn只能順時針轉一次
        所以設定dir的順序要是順時針的
        之後就是每個(i, j)都用dfs暴搜
        過程要用dp記答案
    */

    int lenOfVDiagonal(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
    
        memset(dp, -1, sizeof(dp));

        int res = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    for (int d = 0; d < 4; ++d)
                        res = max(res, dfs(i + dir[d][0], j + dir[d][1], d, 0, 2, grid) + 1);
                }
            }
        }

        return res;
    }
};


int main()
{
    Solution S;
    vector<vector<int>> grid = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    S.lenOfVDiagonal(grid);

    return 0;
}