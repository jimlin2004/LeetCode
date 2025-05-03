#include <bits/stdc++.h>
using namespace std;


// #define maxn 100005
#define maxn 105
#define maxk 75
#define MOD 1000000007

class Solution 
{
public:
    int dp[maxn][maxk];
    // dp[最大值是i][用最多k個值加總] = 總共有多少
    // dp[i][k] = (dp[i - 1][k - 1] + nums[i]) + dp[i - 1][k]
    
    int minMaxSums(vector<int>& nums, int k) 
    {
        memset(dp, 0, sizeof(dp));

        int n = nums.size();

        for (int i = 1; i <= n; ++i)
            dp[i][1] = 2 * nums[i - 1] + dp[i - 1][1];
        
        for (int j = 2; j <= k; ++j)
        {
            for (int i = 1; i <= n; ++i)
            {
                dp[i][j] = dp[i - 1][j - 1] + nums[i - 1] + dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }
        
        return dp[n][k];
    }
};


int main()
{
    vector<int> nums = {1,2,3};
    int k = 2;
    Solution S;
    S.minMaxSums(nums, k);
}