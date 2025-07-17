#include <bits/stdc++.h>
using namespace std;

/*
    基本上就是用資料結構模擬題目要求即可
*/

struct Room
{
    int id;
    long long time;
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

        set<int> available; // 目前可以使用的房間

        for (int i = 0; i < n; ++i)
            available.insert(i);

        priority_queue<Room> pq;

        int m = meetings.size();

        for (int i = 0; i < m; ++i)
        {
            while (!pq.empty() && pq.top().time <= meetings[i][0])
            {
                Room room = pq.top();
                pq.pop();
                available.insert(room.id);
            }

            if (!available.empty()) // 有空房間
            {
                int roomID = *available.begin();
                available.erase(available.begin());
                pq.push({roomID, meetings[i][1]}); // 結束時間直接是meeting的結束時間

                ++cnt[roomID];
            }
            else // 沒有空房間
            {
                // 拿出最早結束的那間房間
                // 且若有多個房間會一起結束，會使用id最小的(Room的比較有處理)
                Room room = pq.top();
                pq.pop();

                room.time += (meetings[i][1] - meetings[i][0]);
                pq.push(room);
                
                ++cnt[room.id];
            }
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

