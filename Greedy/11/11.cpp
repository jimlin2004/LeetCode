#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    /*
        概念: Greedy 
            當高度要變低的時候，保持原高度並讓寬度越長越好(面積才會大)
            用雙指標(頭尾L、R)，為了讓面積越大越好，我們檢查
            if (height[L] < height[R]) then ++L
            else then --R
            如此在保持高度較大的一邊的同時去移動另一邊嘗試得到更大的面積
            可將暴力的O(n^2) -> O(n)
    */
    int maxArea(vector<int>& height) 
    {
        int L = 0;
        int R = height.size() - 1;
        int res = -1;
        int width, h;
        while (L < R)
        {
            h = min(height[L], height[R]);
            width = R - L;
            res = max(res, h * width);
            if (height[L] < height[R])
                ++L;
            else
                --R;
        }
        return res;
    }
};