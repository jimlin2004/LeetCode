#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        題意: 要移除最大與最小的數字，數字都唯一，所謂移除只能從front或back拿掉，要求最小步數
        解法: 很簡單，枚舉三種可能(都從左邊、都從右邊、一左一右)選最好
    */
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1)
            return 1;
        
        int leftPos = min_element(nums.begin(), nums.end()) - nums.begin();
        int rightPos = max_element(nums.begin(), nums.end()) - nums.begin();

        if (leftPos > rightPos)
            swap(leftPos, rightPos);
        
        int res = 0x3f3f3f3f;
        // 試試看都從左邊來
        res = min(res, rightPos + 1); // 一路拿到rightPos
        // 試試看都從右邊來
        res = min(res, n - leftPos); // 一路拿到leftPos
        // 試試看一左一右
        res = min(res, leftPos + 1 + (n - rightPos));

        return res;
    }
};