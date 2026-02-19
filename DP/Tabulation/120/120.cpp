#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:

    /*
       2
      3 4
     6 5 7
    4 1 8 3
    */

    // bottom-up加起來即可
    int minimumTotal(vector<vector<int>>& triangle)
    {
        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};