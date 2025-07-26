#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int cnt[105];

    // 水題
    int maxSum(vector<int>& nums) 
    {
        memset(cnt, 0, sizeof(cnt));

        int largest = -0x3f3f3f3f;
        int selectNum = 0;
        int res = 0;

        for (int val: nums)
        {
            largest = max(largest, val);

            if (val >= 0 && cnt[val] == 0)
            {
                res += val;
                ++cnt[val];
                ++selectNum;
            }
        }

        // 防止都是負的且都被刪除
        // 就回傳裡面最大的
        if (selectNum == 0)
            return largest;
        
        return res;
    }
};