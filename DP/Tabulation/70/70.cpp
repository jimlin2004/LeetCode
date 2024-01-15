#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int climbStairs(int n) 
    {
        int dp[50];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution s;
    int n;
    scanf("%d", &n);
    printf("%d", s.climbStairs(n));
    system("pause");
    return 0;
}