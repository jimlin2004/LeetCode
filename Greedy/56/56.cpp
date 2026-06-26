#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 其實就跟選最少線段覆蓋整個數線的greedy一樣
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;

        // 照左端點排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int currPos = intervals[0][1];

        int start = intervals[0][0];

        int i = 0;

        while (i < intervals.size())
        {
            if (currPos < intervals[i][0])
            {
                res.emplace_back(vector<int>{start, currPos});
                // 更新成右端點，greedy
                currPos = intervals[i][1];
                start = intervals[i][0];
            }
            else
            {
                currPos = max(currPos, intervals[i][1]);
            }

            ++i;
        }

        // 最後一個
        res.emplace_back(vector<int>{start, currPos});

        return res;
    }
};