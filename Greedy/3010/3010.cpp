#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 要將整個array分成3分
    // 第一個數字必選
    // 後面兩段用O(n)維護找
    int minimumCost(vector<int>& nums)
    {
        int min1 = 0x3f3f3f3f;
        int min2 = 0x3f3f3f3f;

        int n = nums.size();

        for (int i = 1; i < n; ++i)
        {
            if (min1 >= nums[i])
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if (min2 > nums[i])
            {
                min2 = nums[i];
            }
        }

        return nums[0] + min1 + min2;
    }
};