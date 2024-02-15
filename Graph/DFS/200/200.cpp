#include <vector>
#include <cstring>
using namespace std;

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        this->h = grid.size();
        this->w = grid[0].size();
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++this->res;
                    this->dfs(i, j, grid);
                }
            }
        }
        return this->res;
    }
private:
    int directions[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    int res = 0;
    int w, h;
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        for (int d = 0; d < 4; ++d)
        {
            int newX = j + this->directions[d][0];
            int newY = i + this->directions[d][1];
            if (newX >= 0 && newX < this->w && newY >= 0 && newY < this->h)
                this->dfs(newY, newX, grid);
        }
    }
};