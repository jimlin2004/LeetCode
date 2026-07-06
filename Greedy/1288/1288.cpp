#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 簡單greedy
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        // 先照左邊排小的在前面，再照右邊排大的在前面
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            if (lhs[0] == rhs[0])
                return lhs[1] > rhs[1];
            return lhs[0] < rhs[0];
        });

        // 至少一個
        int res = 1;

        int n = intervals.size();
        int l = 0, r = 1;
        while (r < n)
        {
            if (intervals[l][0] <= intervals[r][0] && intervals[r][1] <= intervals[l][1])
                ++r;
            else
            {
                l = r;
                ++r;
                ++res;
            }
        }

        return res;
    }
};