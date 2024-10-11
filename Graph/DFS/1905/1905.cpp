#include <vector>
using namespace std;

class Solution 
{
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int res = 0;
        this->m = grid1.size();
        this->n = grid1[0].size();
        for (int i = 0; i < this->m; ++i)
        {
            for (int j = 0; j < this->n; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    //這裡要先確認是不是都有
                    bool isSubLsland = (grid1[i][j] == grid2[i][j]);
                    dfs(grid1, grid2, i, j, isSubLsland);
                    if (isSubLsland)
                        ++res;
                }
            }
        }
        return res;
    }
private:
    int m, n;
    int dir[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    inline bool isVaild(int x, int y)
    {
        return (0 <= x) && (x < this->n) && (0 <= y) && (y < this->m); 
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& isSubLsland)
    {
        grid2[i][j] = 0;
        for (int d = 0; d < 4; ++d)
        {
            int newx = j + this->dir[d][0];
            int newy = i + this->dir[d][1];
            if (isVaild(newx, newy) && grid2[newy][newx])
            {
                isSubLsland = isSubLsland && (grid1[newy][newx] == grid2[newy][newx]);
                dfs(grid1, grid2, newy, newx, isSubLsland);
            }
        }
    }
};

int main()
{
    vector<vector<int>> g1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> g2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    Solution s;
    s.countSubIslands(g1, g2);
}