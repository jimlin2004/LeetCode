#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int n = colors.size();
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            int maxTime = neededTime[i]; // 找到這一段相同的顏色裡time最大的
            int totalTime = neededTime[i]; // 這一段相同的顏色裡time的總和
            while (i + 1 < n && colors[i] == colors[i + 1])
            {
                ++i;
                maxTime = max(maxTime, neededTime[i]);
                totalTime += neededTime[i];
            }

            res += totalTime - maxTime; // 計算最少剩一個的成本
        }

        return res;
    }
};