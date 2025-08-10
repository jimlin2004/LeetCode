#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        由於只要子序列 長度m
        所以當枚舉左邊的i時
        子序列的最右邊只要位於i + m - 1後都可以
        所以先用rightMax與rightMin維護包含自己的右邊最大最小值 O(n)
        枚舉i時看右邊配合誰會最大即可 O(n)
    */
    long long maximumProduct(vector<int>& nums, int m)
    {
        int n = nums.size();

        vector<int> rightMax(n + 5, -0x3f3f3f3f);
        vector<int> rightMin(n + 5, 0x3f3f3f3f);

        for (int i = n - 1; i >= 0; --i)
        {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }

        long long res = -0x3f3f3f3f3f3f3f3f;

        for (int i = 0; i < n - m + 1; ++i)
        {
            res = max({res, (long long)nums[i] * rightMax[i + m - 1], (long long)nums[i] * rightMin[i + m - 1]});
        }

        return res;
    }
};


int main()
{
    vector<int> nums = {-1, 1};
    Solution S;
    S.maximumProduct(nums, 2);

    return 0;
}