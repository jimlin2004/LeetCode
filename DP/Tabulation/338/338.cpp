#include <vector>
using namespace std;

// 利用i >> 1代表右移1bit的方式推表格
class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};