#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int fib(int n) 
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        this->dp[0] = 0;
        this->dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
private:
    long long int dp[100];
};

int main()
{
    int n;
    scanf("%d", &n);
    Solution s;
    printf("%d", s.fib(n));
    system("pause");
}