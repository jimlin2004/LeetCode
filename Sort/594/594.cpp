#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 排序後數一下結束
    int findLHS(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> cnt;
        int prev = nums[0];
        int currCnt = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == prev)
                ++currCnt;
            else
            {
                cnt.push_back({prev, currCnt});
                prev = nums[i];
                currCnt = 1;
            }
        }
        // 最後一個
        cnt.push_back({prev, currCnt});

        int res = 0;

        for (int i = 1; i < cnt.size(); ++i)
        {
            if (cnt[i - 1].first == cnt[i].first - 1)
            {
                res = max(res, cnt[i - 1].second + cnt[i].second);
            }
        }

        return res;
    }
};