#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    //我用類似range dp的概念枚舉所有切點
    int integerBreak(int n) 
    {
        memset(dp, -1, sizeof(dp));
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        return this->solve(n);
    }
private:
    int dp[60];

    int solve(int n)
    {
        if(n <= 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int ans = 1;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, i * solve(n - i));
        }
        return dp[n] = ans;
    }
};

int main()
{
    Solution s;
    printf("%d\n", s.integerBreak(5));
    return 0;
}