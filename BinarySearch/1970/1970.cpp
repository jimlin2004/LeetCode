#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
這題歸為hard
但由於題目是要找到第一個true, true, true, ..., true, false, false,...的最後一個true的地方
所以就只是二分搜 + bfs檢查即可
*/

class Solution 
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        int l = 0, r = cells.size() - 1;
        int res;
        int mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (check(row, col, cells, mid))
            {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        //記得+1，題目一開始多一天
        return res + 1;
    }
private:
    int dir[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    bool check(int row, int col, vector<vector<int>>& cells, int day)
    {
        vector<vector<int>> grid(row + 5, vector<int>(col + 5));
        for (int i = 0; i <= day; ++i)
        {
            //1代表不可過
            grid[cells[i][0]][cells[i][1]] = 1;
        }

        for (int j = 1; j <= col; ++j)
        {
            //第一層都去試試看
            if (grid[1][j] == 0)
            {
                if (bfs(row, col, grid, j, 1))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool bfs(int row, int col, vector<vector<int>>& grid, int sx, int sy)
    {
        queue<pair<int, int>> q;
        q.push({sy, sx});
        
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            if (grid[p.first][p.second] == 1)
                continue;
            if (p.first == row)
                return true;
            grid[p.first][p.second] = 1;
            for (int d = 0; d < 4; ++d)
            {
                int newx = p.second + dir[d][0];
                int newy = p.first + dir[d][1];
                if ((0 < newx) && (newx <= col) && (0 < newy) && (newy <= row))
                {
                    q.push({newy, newx});
                }
            }
        }
        return false;
    }
};

int main()
{
    int row = 2;
    int col = 2;
    vector<vector<int>> cells = {{1,1},{1,2},{2,1},{2,2}};
    Solution s;
    s.latestDayToCross(row, col, cells);
}