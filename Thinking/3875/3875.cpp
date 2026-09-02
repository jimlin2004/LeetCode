#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool uniformArray(vector<int>& nums1) 
    {
        // int n = nums1.size();
        // // 試試看全偶數
        // // 要嘛都是偶數要嘛有2個以上奇數就可以
        // int oddCnt = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     if (nums1[i] & 1)
        //         ++oddCnt;
        // }
        // if (oddCnt == 0 || oddCnt >= 2)
        //     return true;
        // // 試試看全奇數
        // // 要嘛全奇數要嘛至少一個奇數
        // // 所以就是至少一個奇數
        // if (oddCnt >= 1)
        //     return true;
        return true; // 所以答案就是永遠可以
    }
};