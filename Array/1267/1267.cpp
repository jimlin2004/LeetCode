#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    static const int maxn = 255;
    
    // 簡單解法
    // 先算完每個row與col的數量
    // 之後檢查是否唯一
    int countServers(vector<vector<int>>& grid) 
    {
        int rowCnt[maxn];
        int colCnt[maxn];
        memset(rowCnt, 0, sizeof(rowCnt));
        memset(colCnt, 0, sizeof(colCnt));

        int m = grid.size();
        int n = grid[0].size();
        int serverCnt = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                rowCnt[i] += grid[i][j];
                colCnt[j] += grid[i][j];
                serverCnt += grid[i][j];
            }
        }

        int isolated = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] && rowCnt[i] == 1 && colCnt[j] == 1)
                    ++isolated;
            }
        }
        return serverCnt - isolated;
    }
};