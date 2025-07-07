#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 用起點終點排序 + min heap枚舉每一天能參加的活動
    // greedy O(nlogn)
    int maxEvents(vector<vector<int>>& events)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        sort(events.begin(), events.end()); // 先照起點排、再照終點排

        int n = events.size();

        int maxDay = 0;
        for (auto& event: events)
            maxDay = max(maxDay, event[1]);

        int res = 0;

        // 第i個event
        int i = 0;
        // 迭代每一天
        for (int day = 0; day <= maxDay; ++day)
        {
            // 將目前起點小於當前day的event結束時間都放到min heap
            while (i < n && events[i][0] <= day)
            {
                pq.push(events[i][1]);
                ++i;
            }
            
            // 拿掉來不及參加的
            while (!pq.empty() && pq.top() < day)
            {
                pq.pop();
            }

            // 可以參加當前最早結束的event
            if (!pq.empty())
            {
                pq.pop();
                ++res;
            }
        }

        return res;
    }
};