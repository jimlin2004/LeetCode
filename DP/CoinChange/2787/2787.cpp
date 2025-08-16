#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int dp[305];
    const int MOD = 1000000007;

    /*
        題目想一下就知道只是簡單的換硬幣問題
        問用所有的數字(只能用一次)能夠多少種方法湊出n
        -> 將所有的數字當作items，之後dp換硬幣簡單解決
    */

    int numberOfWays(int n, int x)
    {
        vector<int> items;
        for (long long i = 1; i <= n; ++i)
        {
            long long val = 1;
            for (int j = 0; j < x; ++j)
            {
                val *= i;
            }

            if (val > n)
                break;
            items.emplace_back(val);
        }

        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for (int i = 0; i < items.size(); ++i)
        {
            for (int j = n; j >= items[i]; --j)
            {
                dp[j] = (dp[j] + dp[j - items[i]]) % MOD;
            }
        }

        return dp[n];
    }
};


int main()
{
    Solution S;
    S.numberOfWays(4, 1);

    return 0;
}