#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dis[405][405];
    bool vis[405][405];

    int dir[4][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    inline bool isValid(int i, int j, int n)
    {
        return (i >= 0) && (i < n) && (j >= 0) && (j < n);
    }

    // 從每個有thief的cell做bfs找到每個cell的safe factor是多少
    void bfs(const vector<vector<int>>& grid)
    {
        memset(dis, 0x3f, sizeof(dis));
        int n = grid.size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dis[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int ni = curr.first + dir[d][1];
                int nj = curr.second + dir[d][0];

                if (isValid(ni, nj, n) && (dis[ni][nj] > dis[curr.first][curr.second] + 1))
                {
                    dis[ni][nj] = dis[curr.first][curr.second] + 1;
                    q.push(make_pair(ni, nj));
                }
            }
        }
    }

    bool existsPath(int i, int j, int ti, int tj, int minF, const vector<vector<int>>& grid)
    {
        if (i == ti && j == tj)
            return true;

        vis[i][j] = true;
        for (int d = 0; d < 4; ++d)
        {
            int ni = i + dir[d][1];
            int nj = j + dir[d][0];

            if (isValid(ni, nj, grid.size()) && !vis[ni][nj] && dis[ni][nj] >= minF)
            {
                if (existsPath(ni, nj, ti, tj, minF, grid))
                    return true;
            }
        }

        return false;
    }

    /*
        題目要求任意路徑距離所有thief的最短曼哈頓距離是多少
        會想要還是需要將所有cell的最短曼哈頓先算好
        所以只好使用bfs從所有thief出發

        然後要找所有路徑的最小曼哈頓距離
        一個個找會慢，所以改用二分搜找答案
        然後每次用dfs找是不是有路徑還是可以走的到
    */
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        bfs(grid);

        int n = grid.size();

        int l = -1, r = grid.size() + 1;
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            memset(vis, 0, sizeof(vis));
            // 因為existsPath的設計，要記得檢查起點
            if (dis[0][0] >= mid && existsPath(0, 0, n - 1, n - 1, mid, grid))
                l = mid;
            else
                r = mid;
        }

        return l;
    }
};

int main()
{
    vector<vector<int>> grid = {{1}};
    Solution sol;
    sol.maximumSafenessFactor(grid);

    return 0;
}