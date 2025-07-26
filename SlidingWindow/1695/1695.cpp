#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int cnt[10005];

    // 簡單題
    // 滑動窗戶滑一滑就過了
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        memset(cnt, 0, sizeof(cnt));

        int n = nums.size();

        int res = 0;
        int windowSum = 0;

        int l = 0, r = 0;
        while (r < n)
        {
            // 有數字重複
            while (l < r && cnt[nums[r]] > 0)
            {
                --cnt[nums[l]];
                windowSum -= nums[l];
                ++l;
            }

            ++cnt[nums[r]];
            windowSum += nums[r];

            res = max(res, windowSum);
            ++r;
        }

        return res;
    }
};