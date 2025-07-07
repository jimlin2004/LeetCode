#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        // 兩兩石頭相撞，所以其實可以想成分兩堆石頭
        // 每次A堆拿一顆B堆拿一顆互撞，剩下的重量分到保留到其中一堆
        // 最後讓兩堆越平均越好
        // 所以題目就是要分兩堆石頭越平均越好 -> 0/1背包

        bool dp[3005];
        memset(dp, 0, sizeof(dp));

        dp[0] = true;
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = 3004; j >= stones[i]; --j)
            {
                dp[j] |= dp[j - stones[i]]; 
            }
        }

        int total = accumulate(stones.begin(), stones.end(), 0);

        int res;

        for (int i = total / 2; i >= 0; --i)
        {
            if (dp[i])
            {
                res = total - i - i;
                break;
            }
        }

        return res;
    }
};