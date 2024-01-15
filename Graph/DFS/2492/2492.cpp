#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

class Solution 
{
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        memset(this->visited, false, sizeof(this->visited));
        this->G.assign(n + 5, vector<Edge>());
        for (vector<int>& edge: roads)
        {
            G[edge[0]].emplace_back(Edge{edge[0], edge[1], edge[2]});
            G[edge[1]].emplace_back(Edge{edge[1], edge[0], edge[2]});
        }
        this->res = 0x3f3f3f3f;
        this->dfs(1);
        return this->res;
    }
private:
    vector<vector<Edge>> G;
    bool visited[100005];
    int res;

    void dfs(int u)
    {
        this->visited[u] = true;
        for (Edge& edge: this->G[u])
        {
            if (!this->visited[edge.v])
            {
                this->res = min(this->res, edge.w);
                this->dfs(edge.v);
            }
            else
                this->res = min(this->res, edge.w);
        }
    }
};