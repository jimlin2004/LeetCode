#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        在grid中找合法括號路徑
        直覺就是dfs + 剪枝

        由於只能往右或往下
        所以明顯的狀態只有vis[i][j][bal]
        其中bal是左括號與右括號相減的數量

        因為路徑一定是m + n - 1，且bal要平衡一定最多(m + n - 1) / 2
        所以狀態也不多，10^6

        不至於到Hard
    */

    int m, n;
    bool vis[105][105][105];

    bool dfs(int i, int j, int bal, const vector<vector<char>>& grid)
    {
        if (bal < 0) // )比(多
            return false;

        if (vis[i][j][bal])
            return false;

        // 剪枝: 如果剩餘的步數不夠消耗bal，就不可能可以平衡
        int remainSteps = (m - 1 - i) + (n - 1 - j); // 曼哈頓
        if (bal > remainSteps)
            return false;
        
        if (i == m - 1 && j == n - 1)
            return (bal == 0);

        vis[i][j][bal] = true;
        
        // 往右
        if (j + 1 < n)
        {
            int nextBal = bal + (grid[i][j + 1] == '(' ? 1 : -1);
            if (dfs(i, j + 1, nextBal, grid))
                return true;
        }

        // 往下
        if (i + 1 < m)
        {
            int nextBal = bal + (grid[i + 1][j] == '(' ? 1 : -1);
            if (dfs(i + 1, j, nextBal, grid))
                return true;
        }

        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();

        // 剪枝: 路徑長要是偶數，否則無法平衡()
        if ((m + n - 1) % 2 != 0)
            return false;
        // 剪枝: 起點要是(，終點要是)
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')')
            return false;

        memset(vis, 0, sizeof(vis));

        // 在這grid[0][0]已經有一個(
        return dfs(0, 0, 1, grid);
    }
};