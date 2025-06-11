#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    unordered_map<int, int> dp; // 數字太大 -> 離散化

    int dfs(int n)
    {
        if (n <= 1)
            return n;
        
        if (dp.count(n))
            return dp[n];

        int res = 0x3f3f3f3f;
        if (n % 2 == 0)
            res = min(res, dfs(n / 2) + 1);
        if (n % 3 == 0)
            res = min(res, dfs(n / 3) + 1);
        if (n % 2 != 0 || n % 3 != 0)
            res = min(res, dfs(n - 1) + 1);
        return dp[n] = res;
    }

    /*
        如果能吃一半或吃 2/3就吃，總會比-1好
        如果不能被2整除或被3整除，就用-1往下找最接近可以被整除的
    */

    int minDays(int n) 
    {
        return dfs(n);
    }
};


int main()
{
    Solution S;
    S.minDays(10);
    return 0;
}