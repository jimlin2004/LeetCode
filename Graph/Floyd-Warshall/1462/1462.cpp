#include <bits/stdc++.h>
using namespace std;

#define maxn 105

class Solution 
{
public:
    // 就 Floyd Warshall，可以改dp[][]存bool，但我懶
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        int dp[maxn][maxn];
        memset(dp, 0x3f, sizeof(dp));

        for (int i = 0; i < numCourses; ++i)
            dp[i][i] = 0;
        
        for (vector<int>& pre: prerequisites)
            dp[pre[0]][pre[1]] = 1;

        for (int k = 0; k < numCourses; ++k)
            for (int i = 0; i < numCourses; ++i)
                for (int j = 0; j < numCourses; ++j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        
        vector<bool> res;
        for (vector<int>& query: queries)
        {
            if (dp[query[0]][query[1]] == 0x3f3f3f3f)
                res.emplace_back(false);
            else
                res.emplace_back(true);
        }
        return res;
    }
};