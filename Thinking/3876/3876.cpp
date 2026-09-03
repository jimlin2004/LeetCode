#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 3875的延伸題
    // 只多了要檢查是不是有比自己小的odd
    bool uniformArray(vector<int>& nums1) 
    {
        int n = nums1.size();

        // 試試看全偶數
        int minVal = INT_MAX;
        int oddCnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums1[i] & 1)
                ++oddCnt;
            minVal = min(minVal, nums1[i]);
        }
        // 只要多一個奇數，永遠會剩下一個最小的奇數，這時候就不能變成全奇數
        if (oddCnt == 0)
            return true;
        // 試試看全奇數
        // 能全奇數只有當全都是奇數或最小的值是奇數時才可以
        if (oddCnt == n || (minVal & 1))
            return true;
        return false;
    }
};