#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int minimumOperations(vector<int>& nums)
    {
        int cnt[105];
        memset(cnt, 0, sizeof(cnt));

        int res = 0;

        for (int val: nums)
        {
            if (val > 0 && cnt[val] == 0)
                ++res;
            ++cnt[val];
        }

        return res;
    }
};