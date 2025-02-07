#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    unordered_map<int, int> color;
    unordered_map<int, int> cnt;

    // 就hash離散化處理維護顏色與紀錄即可
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        vector<int> resVec;
        int res = 0;
        for (auto& q: queries)
        {
            if (color[q[0]] == 0)
            {
                if (cnt[q[1]] == 0)
                    ++res;
                color[q[0]] = q[1];
                ++cnt[q[1]];
            }
            else // 有顏色了
            {
                int oldColor = color[q[0]];
                if (cnt[oldColor] == 1)
                    --res;
                --cnt[oldColor];
                if (cnt[q[1]] == 0)
                    ++res;
                color[q[0]] = q[1];
                ++cnt[q[1]];
            }

            resVec.emplace_back(res);
        }
        return resVec;
    }
};