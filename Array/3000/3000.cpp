#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // 水題
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions)
    {
        double maxDiagonal = 0;
        int maxArea = 0;

        for (auto& dimension: dimensions)
        {
            double currDiagonal = sqrt(dimension[0] * dimension[0] + dimension[1] * dimension[1]);

            if (maxDiagonal < currDiagonal)
            {
                maxDiagonal = currDiagonal;
                maxArea = dimension[0] * dimension[1];
            }
            else if (maxDiagonal == currDiagonal)
            {
                maxArea = max(maxArea, dimension[0] * dimension[1]);
            }
        }

        return maxArea;
    }
};