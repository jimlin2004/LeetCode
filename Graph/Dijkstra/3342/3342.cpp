#include <bits/stdc++.h>
using namespace std;

struct State
{
    int x, y;
    int dis;
    int nextMoveSec;
};


class Solution
{
public:
    int dir[4][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    int m, n;

    int dis[755][755][3];
    bool vis[755][755][3]; // vis[i][j][nextMoveSec]

    inline bool isValid(int i, int j)
    {
        return (i >= 0) && (i < m) && (j >= 0) && (j < n);
    }

    int dijkstra(const vector<vector<int>>& moveTime)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));

        auto cmp = [](const State& a, const State& b){
            return a.dis > b.dis;
        };

        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

        dis[0][0][1] = 0;
        pq.push({0, 0, 0, 1});

        while (!pq.empty())
        {
            State curr = pq.top();
            pq.pop();

            if (vis[curr.y][curr.x][curr.nextMoveSec])
                continue;

            vis[curr.y][curr.x][curr.nextMoveSec] = true;

            if (curr.y == m - 1 && curr.x == n - 1)
                return curr.dis;

            for (int d = 0; d < 4; ++d)
            {
                int nx = curr.x + dir[d][0];
                int ny = curr.y + dir[d][1];

                if (isValid(ny, nx))
                {
                    int newNextMoveSec = (curr.nextMoveSec == 1) ? 2 : 1;

                    // 如果還不能進去，就在原本房間等到能進
                    int nextRoomReachTime = max(moveTime[ny][nx], dis[curr.y][curr.x][curr.nextMoveSec]);

                    if (nextRoomReachTime + curr.nextMoveSec < dis[ny][nx][newNextMoveSec])
                    {
                        dis[ny][nx][newNextMoveSec] = nextRoomReachTime + curr.nextMoveSec;
                        pq.push({nx, ny, dis[ny][nx][newNextMoveSec], newNextMoveSec});
                    }
                }
            }
        }

        return -1;
    }

    // 就是多一個移動到下一個room的狀態的dijkstra
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        m = moveTime.size();
        n = moveTime[0].size();

        return dijkstra(moveTime);
    }
};

int main()
{
    vector<vector<int>> moveTime = {
        {0,0,0,0},{0,0,0,0}
    };

    Solution sol;
    sol.minTimeToReach(moveTime);
}