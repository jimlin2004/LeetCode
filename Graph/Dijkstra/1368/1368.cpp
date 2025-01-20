#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

struct Item
{
    int u, w;
    bool operator < (const Item& other) const
    {
        return w > other.w;
    }
};

class Solution 
{
private:
    vector<vector<Edge>> G;
    int m, n;
    // dijkstra用
    bool vis[10005];
    int dis[10005];
public:
    inline int to1d(int row, int col, int colSize)
    {
        return row * colSize + col;
    }

    inline bool isValid(int x, int y)
    {
        return (0 <= x) && (x < n) && (0 <= y) && (y < m);
    } 

    int dijkstra(int s, int t)
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        priority_queue<Item> pq;
        dis[s] = 0;
        pq.push({s, 0});
        while (!pq.empty())
        {
            Item curr = pq.top();
            pq.pop();
            if (vis[curr.u])
                continue;
            if (curr.u == t)
                return dis[t];
            vis[curr.u] = true;
            for (Edge& edge: G[curr.u])
            {
                if (dis[edge.v] > dis[curr.u] + edge.w)
                {
                    dis[edge.v] = dis[curr.u] + edge.w;
                    pq.push({edge.v, dis[edge.v]});
                }
            }
        }
        return 0x3f3f3f3f;
    }

    /*
        蠻有趣的題目
        想法是若原本的方向指向的邊cost為0
        其他方向都需要轉向，所以需要多一個cost
        以此方式建密集圖的邊
        之後跑dijkstra到終點的最低成本就是答案
    */
    int minCost(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        // 方向配合題目順序
        int dir[5][2] = {
            {0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        G.assign(m * n + 5, vector<Edge>());
        // 建邊(密集圖)
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int u = to1d(i, j, n);
                for (int d = 1; d <= 4; ++d)
                {
                    int nx = j + dir[d][0];
                    int ny = i + dir[d][1];
                    if (isValid(nx, ny))
                    {
                        int v = to1d(ny, nx, n);
                        // 如果原本方向不指向v，就要多一次cost
                        int cost = (grid[i][j] != d);
                        G[u].emplace_back(Edge{u, v, cost});
                    }
                }
            }
        }

        return dijkstra(0, m * n - 1);
    }
};

int main()
{
    vector<vector<int>> grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    Solution s;
    s.minCost(grid);
    return 0;
}