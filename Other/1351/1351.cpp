#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int cnt = 0;
        // 利用題目特性
        // 走斜對角能做到O(n + m)

        int i = 0, j = grid[0].size() - 1;
        int rowCnt = 0;

        while (i < grid.size())
        {
            while (j >= 0 && grid[i][j] < 0)
            {
                ++rowCnt;
                --j;
            }
            cnt += rowCnt;
            ++i;
        }

        return cnt;
    }
};


int main()
{
    vector<vector<int>> input = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    Solution S;
    S.countNegatives(input);
}