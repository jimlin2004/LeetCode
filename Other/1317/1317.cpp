#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 有沒有0
    bool check(int n)
    {
        while (n > 0)
        {
            if (n % 10 == 0)
                return false;
            n /= 10;
        }
        return true;
    }

    // 水題
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 1; i < n; ++i)
        {
            if (check(i) && check(n - i))
            {
                return {i, n - i};
            }
        }

        return {0, 0}; // 不會到這邊
    }
};