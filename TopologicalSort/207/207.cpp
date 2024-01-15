#include <vector>
#include <cstring>
#include <queue>
using namespace std;

class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        this->adj.resize(numCourses);
        memset(this->indegree, 0, numCourses);
        for (vector<int>& e: prerequisites)
        {
            this->adj[e[1]].push_back(e[0]);
            this->indegree[e[0]]++;
        }
        return this->kahn();
    }
    
    bool kahn()
    {
        queue<int> q;
        int n = this->adj.size();
        for (int i = 0; i < this->adj.size(); ++i)
        {
            if (this->indegree[i] == 0)
                q.push(i);
        }

        int u;
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            --n;
            for (int v: this->adj[u])
            {
                if (--this->indegree[v] == 0)
                    q.push(v);
            }
        }
        return (n == 0);
    }
private:
    vector<vector<int>> adj;
    int indegree[2005];
};