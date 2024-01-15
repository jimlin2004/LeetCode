#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v;
    int d;
    bool operator < (const Edge& other) const
    {
        return this->d < other.d;
    }
};

class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        fill(this->disjointSet, this->disjointSet + 1005, -1);
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                this->edges.push_back({i, j, this->getDistance(points[i][0], points[i][1], points[j][0], points[j][1])});
            }
        }
        return this->kruskal(points.size() - 1);
    }
private:
    vector<Edge> edges;

    int disjointSet[1005];

    int find(int root)
    {
        if (this->disjointSet[root] < 0)
            return root;
        return this->disjointSet[root] = this->find(this->disjointSet[root]);
    }

    bool Union(int r1, int r2)
    {
        int p1 = this->find(r1);
        int p2 = this->find(r2);
        if (p1 == p2)
            return false;
        if (p1 < p2)
        {
            this->disjointSet[p1] += this->disjointSet[p2];
            this->disjointSet[p2] = p1;
        }
        else
        {
            this->disjointSet[p2] += this->disjointSet[p1];
            this->disjointSet[p1] = p2;
        }
        return true;
    }

    int kruskal(int edgeNum)
    {
        sort(this->edges.begin(), this->edges.end());
        int currentEdgeNum = 0;
        int res = 0;
        for (Edge& edge: this->edges)
        {
            if (this->Union(edge.u, edge.v))
            {
                res += edge.d;
                ++currentEdgeNum;
            }
            if (currentEdgeNum == edgeNum)
                break;
        }
        return res;
    }

    int getDistance(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};