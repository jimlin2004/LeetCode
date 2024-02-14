#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int minCost(int n, vector<int>& cuts) 
    {
        //range dp
        memset(this->dp, -1, sizeof(this->dp));
        sort(cuts.begin(), cuts.end());
        this->cost[0] = 0;
        for (int i = 0; i < cuts.size(); ++i)
        {
            this->cost[i + 1] = cuts[i];
        }
        this->cost[cuts.size() + 1] = n;
        return this->solve(0, cuts.size() + 1);
    }
private:
    //dp[i][j] -> [i, j]區間中最小的cost
    int dp[105][105];
    int cost[105];
    int solve(int i, int j)
    {
        if (this->dp[i][j] != -1)
            return this->dp[i][j];
            //區間只有一種切法: cost[j] - cost[i]
        if (i == j - 1)
            return dp[i][j] = 0;
        int currCost = 0x3f3f3f3f;
        //枚舉中間切點
        for (int m = i + 1; m < j; ++m)
        {
            currCost = min(currCost, this->solve(i, m) + this->solve(m, j) + this->cost[j] - this->cost[i]);
        }
        return this->dp[i][j] = currCost;
    }
};