#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<pair<int, double>> adj[10000];
        int from, to;
        for (int i = 0; i < edges.size(); i++)
        {
            from = edges[i][0];
            to = edges[i][1];
            adj[from].push_back({to, succProb[i]});
            adj[to].push_back({from, succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> distance(n, 0.0);
        pq.push({1.0, start});
        distance[start] = 1.0;
        double cost;
        int node;
        while  (!pq.empty())
        {
            cost = pq.top().first;
            node = pq.top().second;
            pq.pop();
            for (auto e: adj[node])
            {
                if (distance[e.first] < e.second * cost)
                {
                    distance[e.first] = e.second * cost;
                    pq.push({distance[e.first], e.first});
                }
            }
        }
        return distance[end];
    }
};