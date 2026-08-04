#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    vector<int> findMissingElements(vector<int>& nums)
    {
        int cnt[105];

        memset(cnt, 0, sizeof(cnt));

        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for (int val: nums)
        {
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
            ++cnt[val];
        }

        vector<int> res;

        for (int i = minVal + 1; i < maxVal; ++i)
        {
            if (cnt[i] == 0)
                res.emplace_back(i);
        }

        return res;
    }
};