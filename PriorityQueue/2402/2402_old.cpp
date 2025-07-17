#include <bits/stdc++.h>
using namespace std;

/*
n = 4
meetings = [[18,19],[3,12],[17,19],[2,13],[7,10]]
會錯
答案是0
我回答2

這是因為多個房間都可以的時候要用id最小的
但我的pq會先給出time最小的，不會考慮所有可以的房間裡id最小的
*/

struct Room
{
    int id;
    int time;
    bool operator < (const Room& other) const
    {
        if (time == other.time)
            return id > other.id;
        return time > other.time;
    }
};

class Solution 
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        vector<int> cnt(n + 5, 0); // 每個房間被用幾次

        priority_queue<Room> pq;
        for (int i = 0; i < n; ++i)
        {
            pq.push({i, 0});
        }

        int m = meetings.size();

        for (int i = 0; i < m; ++i)
        {
            Room room = pq.top();
            pq.pop();

            if (room.time < meetings[i][0])
            {
                room.time = meetings[i][0];
            }

            room.time += meetings[i][1] - meetings[i][0];

            ++cnt[room.id];

            pq.push(room);
        }

        int maxCnt = 0;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (cnt[i] > maxCnt)
            {
                maxCnt = cnt[i];
                res = i;
            }
        }

        return res;
    }
};


int main()
{
    Solution S;
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    S.mostBooked(2, meetings);

    return 0;
}

