#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool isBoomerang(vector<vector<int>>& points) 
    {
        if (points[0] == points[1] || points[0] == points[2] || points[1] == points[2])
            return false;

        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        
        // 使用外積判斷是否共線
        // (y2 - y1) / (x2 - x1) != (y3 - y1) / (x3 - x1) 移項後的結果
        return (y2 - y1) * (x3 - x1) != (y3 - y1) * (x2 - x1);
    }
};