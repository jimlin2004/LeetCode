#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int solve(vector<vector<int>>& grid, int ql, int qr, int qu, int qb)
    {
        if (ql > qr || qu > qb)
            return -1;
        if (ql < 0 || qu < 0)
            return -1;

        int l = 0x3f3f3f3f;
        int r = -1;
        int u = 0x3f3f3f3f;
        int b = -1;

        bool hasOne = false;

        for (int i = qu; i <= qb; ++i)
        {
            for (int j = ql; j <= qr; ++j)
            {
                if (grid[i][j] == 1)
                {
                    hasOne = true;
                    u = min(u, i);
                    b = max(b, i);
                    l = min(l, j);
                    r = max(r, j);
                }
            }
        }

        return (hasOne) ? (r - l + 1) * (b - u + 1) : -1;
    }

    /*
        所有切割方式有6種
        即 (示意圖，重點是相對位置，數字不代表搜尋順序)
        (1)              (2)             (3)
            1 1 1 1 1 1     1 1 1 2 2 2     1 1 1 1 1 1
            1 1 1 1 1 1     1 1 1 2 2 2     1 1 1 1 1 1
            2 2 2 3 3 3     3 3 3 3 3 3     2 2 2 2 2 2
            2 2 2 3 3 3     3 3 3 3 3 3     3 3 3 3 3 3

        (4)              (5)             (6)
            1 1 1 2 2 2     1 1 1 3 3 3     1 1 2 2 3 3
            1 1 1 2 2 2     1 1 1 3 3 3     1 1 2 2 3 3
            1 1 1 3 3 3     2 2 2 3 3 3     1 1 2 2 3 3
            1 1 1 3 3 3     2 2 2 3 3 3     1 1 2 2 3 3
        然後去搜每個區塊最小只需要多少面積加起來即可
    */
    int minimumSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int res = 0x3f3f3f3f;

        // 枚舉第一種
        for (int y1 = 0; y1 < m; ++y1)
        {
            int area1 = solve(grid, 0, n - 1, 0, y1);
            if (area1 == -1)
                continue;
            for (int x1 = 0; x1 < n; ++x1)
            {
                int area2 = solve(grid, 0, x1, y1 + 1, m - 1);
                int area3 = solve(grid, x1 + 1, n - 1, y1 + 1, m - 1);

                if (area2 == -1 || area3 == -1)
                    continue;
                
                res = min(res, area1 + area2 + area3);
            }
        }

        // 枚舉第二種
        for (int y1 = m - 1; y1 >= 0; --y1)
        {
            int area1 = solve(grid, 0, n - 1, y1, m - 1);
            if (area1 == -1)
                continue;
            for (int x1 = 0; x1 < n; ++x1)
            {
                int area2 = solve(grid, 0, x1, 0, y1 - 1);
                int area3 = solve(grid, x1 + 1, n - 1, 0, y1 - 1);

                if (area2 == -1 || area3 == -1)
                    continue;
                
                res = min(res, area1 + area2 + area3);
            }
        }

        // 枚舉第三種
        for (int y1 = 0; y1 < m; ++y1)
        {
            int area1 = solve(grid, 0, n - 1, 0, y1);
            if (area1 == -1)
                continue;
            for (int y2 = y1 + 1; y2 < m; ++y2)
            {
                int area2 = solve(grid, 0, n - 1, y1 + 1, y2);
                int area3 = solve(grid, 0, n - 1, y2 + 1, m - 1);

                if (area2 == -1 || area3 == -1)
                    continue;
                
                res = min(res, area1 + area2 + area3);
            }
        }

        // 枚舉第四種
        for (int x1 = 0; x1 < n; ++x1)
        {
            int area1 = solve(grid, 0, x1, 0, m - 1);
            if (area1 == -1)
                continue;
            for (int y1 = 0; y1 < m; ++y1)
            {
                int area2 = solve(grid, x1 + 1, n - 1, 0, y1);
                int area3 = solve(grid, x1 + 1, n - 1, y1 + 1, m - 1);
                if (area2 == -1 || area3 == -1)
                    continue;
                
                res = min(res, area1 + area2 + area3);
            }
        }

        // 枚舉第五種
        for (int x1 = n; x1 >= 0; --x1)
        {
            int area1 = solve(grid, x1, n - 1, 0, m - 1);
            if (area1 == -1)
                continue;
            for (int y1 = 0; y1 < m; ++y1)
            {
                int area2 = solve(grid, 0, x1 - 1, 0, y1);
                int area3 = solve(grid, 0, x1 - 1, y1 + 1, m - 1);
                if (area2 == -1 || area3 == -1)
                    continue;
                
                res = min(res, area1 + area2 + area3);
            }
        }

        // 枚舉第六種
        for (int x1 = 0; x1 < n; ++x1)
        {
            int area1 = solve(grid, 0, x1, 0, m - 1);
            if (area1 == -1)
                continue;
            for (int x2 = x1 + 1; x2 < n; ++x2)
            {
                int area2 = solve(grid, x1 + 1, x2, 0, m - 1);
                int area3 = solve(grid, x2 + 1, n - 1, 0, m - 1);
                if (area2 == -1 || area3 == -1)
                    continue;
                
                res = min(res, area1 + area2 + area3);
            }
        }

        return res;
    }
};


int main()
{
    vector<vector<int>> grid = {{1,0,1}, {1,1,1}};
    Solution S;
    S.minimumSum(grid);

    return 0;
}