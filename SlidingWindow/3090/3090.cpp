#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 滑動窗戶水題
    int maximumLengthSubstring(string s)
    {
        int windowCnts[300];
        memset(windowCnts, 0, sizeof(windowCnts));
    
        int res = 0;

        int n = s.size();
        int l = 0, r = 0;
        while (r < n)
        {
            ++windowCnts[s[r]];
            while (windowCnts[s[r]] > 2)
            {
                --windowCnts[s[l]];
                ++l;
            }

            res = max(res, r - l + 1);
            ++r;
        }

        return res;
    }
};