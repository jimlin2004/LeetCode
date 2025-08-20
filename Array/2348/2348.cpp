#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        簡單題
        00比0多2個
        000比00多3個

        其實就是因為每多一個0
        就多了0、00、000、0000 ... 到n個0
        所以數一下加起來就行了
    */
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long res = 0;
        
        int n = nums.size();
        int cnt = 0; // 連續幾個0
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
                ++cnt;
            else
                cnt = 0;

            res += cnt;
        }

        return res;
    }
};