#include <vector>
#include <algorithm>
using namespace std;

/*
掃瞄線演算法
將左端點與右端點拆開來
左端點的放segment新加進去的值
右端點出現segment結束了，所以放要扣掉的值
當出現上一個點與現在的點不一樣且total大於0就代表出現了新的線段
*/

class Solution 
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) 
    {
        vector<pair<int, int>> points;
        for (vector<int>& segment: segments)
        {
            //左端點
            points.emplace_back(pair{segment[0], segment[2]});
            //右端點
            points.emplace_back(pair{segment[1], -segment[2]});
        }
        sort(points.begin(), points.end());
        vector<vector<long long>> res;
        // 掃描線
        long long total = points[0].second;
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i].first != points[i - 1].first && total > 0)
            {
                res.push_back({points[i - 1].first, points[i].first, total});
            }
            total += points[i].second;
        }
        return res;
    }
};