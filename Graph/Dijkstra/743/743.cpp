#include <queue>
#include <vector>
using namespace std;

class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        const int oo = 1000;
        vector<pair<int, int>> adj[101];
        int distance[101];
        priority_queue<pair<int, int>> pq;
        bool visited[101];
        for (int i = 0; i < times.size(); i++)
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        for (int i = 0; i < n; i++)
            distance[i] = oo;
        distance[k] = 0;
        pq.push({distance[k], k});
        int u, v, w;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            v = p.second;
            if (visited[v])
                continue;
            visited[v] = true;
            for (auto e: adj[v])
            {
                u = e.first;
                w = e.second;
                if (distance[v] + w < distance[u])
                {
                    distance[u] = distance[v] + w;
                    pq.push({-distance[u], u});
                }
            }
        }
        int maxd = -1;        
        for (int i = 0; i < n; i++)
        {
            if (!visited[n])
                return -1;
            if (distance[i] < oo)
            {
                maxd = max(maxd, distance[i]);
            }
        }
        return maxd;
    }
};