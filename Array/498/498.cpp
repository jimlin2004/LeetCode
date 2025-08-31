#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 照著實作就是了
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int dir = 1; // 移動方向(右上或左下)
        int i = 0, j = 0;

        vector<int> res;

        while (true)
        {
            res.emplace_back(mat[i][j]);
            
            if (i == m - 1 && j == n - 1)
                break;
            
            // 處理轉向
            if (i - dir < 0 || i - dir >= m || j + dir < 0 || j + dir >= n)
            {
                if (dir == 1)
                {
                    if (j + 1 < n)
                        j += 1;
                    else
                        i += 1;
                }
                else
                {
                    if (i + 1 < m)
                        i += 1;
                    else
                        j += 1;
                }
                
                dir = -dir; // 轉向
            }
            else
            {
                i -= dir;
                j += dir;
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}};
    Solution S;
    S.findDiagonalOrder(mat);

    return 0;
}