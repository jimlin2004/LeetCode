#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 用backtracking找有沒有辦法能夠加出target
    bool dfs(int sum, int n, int target)
    {
        if (sum > target)
            return false;
        // 一位一位數添加看看
        int mask = 10;
        while (mask < n)
        {
            // 找到就回傳true
            if (dfs(sum + (n % mask), n / mask, target))
                return true;
            mask *= 10;
        }
        // 最後要檢查整個n不分的情況下能不能加出數字
        return sum + n == target;
    }

    // 暴搜 1 ~ n
    int punishmentNumber(int n) 
    {
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            int square = i * i;
            if (dfs(0, square, i))
                res += square;
        }
        return res;
    }
};

int main()
{
    Solution S;
    S.punishmentNumber(37);

    return 0;
}