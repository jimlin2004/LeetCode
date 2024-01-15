#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<int> v;
        this->len = graph.size() - 1;
        this->dfs(graph, 0, v);
        return this->res;
    }
private:
    vector<vector<int>> res;
    int len;
    void dfs(vector<vector<int>>& graph, int s, vector<int> vec)
    {
        vec.push_back(s);
        if (graph[s].size() == 0 && s == this->len)
        {
            this->res.push_back(vec);
            return ;
        }
        for (int n: graph[s])
        {
            this->dfs(graph, n, vec);
        }
        return ;
    }
};