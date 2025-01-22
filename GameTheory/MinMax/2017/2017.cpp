#include <bits/stdc++.h>
using namespace std;

#define maxn 50005

class Solution 
{
public:
    // 這題不是DP，而是min max
    // 因為只有兩個row，所以題目變得特殊化
    // 對於第一個player來說，他可以在第一row的第k格往下(此時第一row的1 ~ k清成0)
    // 第k格往下後第二row的k ~ n也會清成0
    // 所以對於第二個player來說，每次有兩條路可以走
    /*
        若player 1在第k格選擇往下
        此時player 2有兩條路可以玩:
        1. 第一row走到底，最後一格往下，此時palyer 2可總共得到第一row中 k + 1 ~ n的分數
        2. 第一格就往下走，此時player 2總共可得第二row中 1 ~ k - 1的分數
    */
    // 因此player 2可得到的最高分數就是枚舉player 1的n個選擇(第k格往下)
    // 取兩條路線中最大，整體的最小分即為答案
    long long gridGame(vector<vector<int>>& grid) 
    {
        long long prefix[5][maxn];
        int n = grid[0].size();
        for (int i = 0; i < grid.size(); ++i)
        {
            prefix[i][0] = 0;
            for (int j = 1; j <= n; ++j)
                prefix[i][j] = prefix[i][j - 1] + grid[i][j - 1];
        }
        long long secondScore = 0x3f3f3f3f3f3f3f3f;
        for (int k = 1; k <= n; ++k)
        {
            secondScore = min(secondScore, max(prefix[0][n] - prefix[0][k], prefix[1][k - 1]));
        }
        return secondScore;
    }
};

int main()
{
    vector<vector<int>> grid = {{2,5,4},{1,5,1}};
    Solution s;
    s.gridGame(grid);
    return 0;
}