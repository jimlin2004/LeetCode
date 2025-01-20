#include <bits/stdc++.h>
using namespace std;

struct Cell
{
    int i, j, h;
    bool operator < (const Cell& other) const
    {
        return h > other.h;
    }
};

class Solution 
{
public:
    int dir[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    int m, n;

    inline bool isValid(int i, int j)
    {
        return (0 <= i && i < m) && (0 <= j && j < n);
    }

    /*
        官方解
        這題不能用一維那一題的快速方法
        因為在二維中能裝水的地方是一個輪廓
        一個地方能夠裝水是因為它的高度都小於旁邊的高度
        所以對於一個cell他能夠裝的水取決於它鄰居的最小高度

        題解
        這題要用類似BFS的方式
        要維護一個priority_queue用來快速知道現在的最小高度是多少
        一開始要將所有的邊界放到pq中
        從pq中pop出最小高度的cell
        對該cell(curr)的鄰居處理
        若該鄰居的高度小於pq維護的最小高度(誰，就是curr)
        則該鄰居能夠裝得下curr.h - neighbor.h的水
        為什麼，因為pq先出來的一定是當前高度最小的
        代表neighbor的邊界高度最低一定是curr.h
        同時水流neighbor後pq要push進去cell高度為(neighbor.h, curr.h)
        如此邊界才能繼續保持，也不會影響到後面的計算

        算是BFS + greedy
    */
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        m = heightMap.size();
        n = heightMap[0].size();
        
        bool vis[205][205];
        memset(vis, 0, sizeof(vis));
        priority_queue<Cell> pq;
        // 將邊界放進去pq中
        for (int i = 0; i < m; ++i)
        {
            pq.push({i, 0, heightMap[i][0]});
            pq.push({i, n - 1, heightMap[i][n - 1]});
            vis[i][0] = vis[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++j)
        {
            pq.push({0, j, heightMap[0][j]});
            pq.push({m - 1, j, heightMap[m - 1][j]});
            vis[0][j] = vis[m - 1][j] = true;
        }

        int res = 0;
        while (!pq.empty())
        {
            Cell curr = pq.top();
            pq.pop();
            for (int d = 0; d < 4; ++d)
            {
                int ni = curr.i + dir[d][1];
                int nj = curr.j + dir[d][0];
                if (isValid(ni, nj) && !vis[ni][nj])
                {
                    vis[ni][nj] = true;
                    // 水能不能流到鄰居
                    if (heightMap[ni][nj] < curr.h)
                    {
                        res += curr.h - heightMap[ni][nj];
                    }
                    // 維護邊界
                    pq.push({ni, nj, max(heightMap[ni][nj], curr.h)});
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> heights = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    Solution s;
    s.trapRainWater(heights);
    return 0;
}