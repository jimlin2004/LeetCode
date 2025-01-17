#include <bits/stdc++.h>
using namespace std;

struct Line
{
    int l;
    int r;
    int h;
    bool isEnd;
    bool operator < (const Line& other) const
    {
        // 照左端點排序
        if (l == other.l)
            return h > other.h; //左端點一樣時，最高的先出來
        return l < other.l;
    }
};

struct Item
{
    int h;
    int to;
    bool operator < (const Item& other) const
    {
        return this->h < other.h;
    }
};

class Solution 
{
public:
    // heap解法
    // 用掃描線法(拆左與右端點)
    // 同時維護現在合法的線段中高度最高的
    // 若出現高度變化時就是新的key point
    // 用heap每次放線段高度進去
    // 如果heap裡的最大高度的線段已經過期要先pop掉
    // 除了heap還有很多解法(如區間最大值等)
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<Line> lines;
        for (auto& building: buildings)
        {
            lines.push_back({building[0], building[1], building[2], false});
            lines.push_back({building[1], building[1], 0, true});
        }
        sort(lines.begin(), lines.end());
        priority_queue<Item> pq;
        vector<vector<int>> res;
        // 多放一個地平線在pq中
        pq.push({0, INT_MAX});
        for (Line& line: lines)
        {
            while (!pq.empty() && pq.top().to <= line.l)
                pq.pop();
            if (!line.isEnd)
                pq.push({line.h, line.r});
            if (res.empty() || (res.back()[1] != pq.top().h))
                res.push_back({line.l, pq.top().h});
        }
        return res;
    }
};

int main()
{
    // vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    // vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
    vector<vector<int>> buildings = {{0,2147483647,2147483647}};
    Solution s;
    s.getSkyline(buildings);
    return 0;
}