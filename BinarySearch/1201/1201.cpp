#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        用排容原理算 <= m的正整數有多少個數字被a or b or c整除
        數量 = (m / a + m / b + m / c) - (m / lcm(a, b) + m / lcm(b, c) + m / lcm(a, c)) + (m / lcm(a, b, c))
    */
    long long getNum(long long m, long long a, long long b, long long c)
    {
        long long lcm_ab = lcm(a, b);
        long long lcm_ac = lcm(a, c);
        long long lcm_bc = lcm(b, c);
        long long lcm_abc = lcm(lcm(a, b), c);

        return (m / a + m / b + m / c) - (m / lcm_ab + m / lcm_ac + m / lcm_bc) + (m / lcm_abc);
    }

    int nthUglyNumber(int n, int a, int b, int c)
    {
        // 利用二分搜找到最小的m使得 n <= getNum(m)
        long long l = 0, r = 0x3f3f3f3f3f3f3f3f;
        while (l + 1 < r)
        {
            long long mid = l + ((r - l) >> 1);
            // 答案在右半邊
            if (n <= getNum(mid, a, b, c))
                r = mid;
            else
                l = mid;
        }

        // 答案在r
        return r;
    }
};