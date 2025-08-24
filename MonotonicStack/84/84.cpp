#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 經典mono stack應用
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();

        // left[i] -> 在i的左邊最靠近i且height < height[i]的index
        // right[i] -> 在i的右邊最靠近i且height < height[i]的index
        vector<int> left(n + 5, 0);
        vector<int> right(n + 5, 0);

        // 用monoSK維護
        stack<int> monoSK;
        // 處理left[]
        for (int i = 0; i < n; ++i)
        {
            while (!monoSK.empty() && heights[monoSK.top()] >= heights[i])
                monoSK.pop();
            if (monoSK.empty())
                left[i] = -1;
            else
                left[i] = monoSK.top();
            
            monoSK.push(i);
        }

        // 清空sk
        while (!monoSK.empty())
            monoSK.pop();
        
        // 處理right[]
        for (int i = n - 1; i >= 0; --i)
        {
            while (!monoSK.empty() && heights[monoSK.top()] >= heights[i])
                monoSK.pop();
            if (monoSK.empty())
                right[i] = n;
            else
                right[i] = monoSK.top();
            
            monoSK.push(i);
        }

        int res = 0;
        // 枚舉每一根當作矩形最低高度
        for (int i = 0; i < n; ++i)
        {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }

        return res;
    }
};