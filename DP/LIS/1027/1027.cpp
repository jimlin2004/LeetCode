#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //就LIS，改成多一個維度記公差
    //然後正負都要檢查
    int longestArithSeqLength(vector<int>& nums)
    {
        vector<vector<int>> dp_pos(1005, vector<int>(505, 1)); //正公差
        vector<vector<int>> dp_neg(1005, vector<int>(505, 1)); //負公差

        int res = 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            dp_pos[i][0] = 1;
            dp_neg[i][0] = 1;
            for (int j = 0; j < i; ++j)
            {
                int diff = nums[i] - nums[j];
                if (diff > 0)
                {
                    dp_pos[i][diff] = max(dp_pos[i][diff], dp_pos[j][diff] + 1);
                    res = max(res, dp_pos[i][diff]);
                }
                else
                {
                    //轉正
                    diff = -diff;
                    dp_neg[i][diff] = max(dp_neg[i][diff], dp_neg[j][diff] + 1);
                    res = max(res, dp_neg[i][diff]);
                }
            }
        }
        return res;
    }
};