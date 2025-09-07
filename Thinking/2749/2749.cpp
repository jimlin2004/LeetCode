#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    inline long long lowbit(long long x)
    {
        return x & (-x);
    }

    int countBitOne(long long x)
    {
        int cnt = 0;

        while (x)
        {
            x -= lowbit(x);
            ++cnt;
        }

        return cnt;
    }

    /*
        數學推導題(不是自己想到)

        首先
        假設存在答案k使得滿足題目要求
        num1 - (2^i_1 + num2) - (2^i_2 + num2) - ... - (2^i_k + num2) = 0
        (移項) =>
        num1 = 2^i_1 + num2 + 2^i_2 + num2 + ... + 2^i_k + num2
        (有k個num2) =>
        num1 = 2^i_1 + 2^i_2 + ... + 2^i_k + (k * num2)
        (移項) =>
        num1 - k * num2 = 2^i_1 + 2^i_2 + ... + 2^i_k

        此時x = (num1 - k * num2)由k個2的冪次組成
        -> 可以證明需要的2^i最少就是x的二進位有幾個1 (如二進位可以組成所有數字去證明)
        最多就是全部使用2^0 = 1去組成x -> 需要x個2^0
        同時只要是在 x的二進位有幾個1 <= k <= x的k都是答案
        
        所以解法就是從k = 0開始枚舉答案
        如果有答案就是最小的k
        沒有答案就-1
    */
    int makeTheIntegerZero(int num1, int num2)
    {
        int k = 0;

        while (1)
        {
            long long x = (long long)num1 - (long long)num2 * k;

            if (k > x)
                return -1;
            if (k >= countBitOne(x)) // k在上下界中 -> 找到答案
                return k;

            ++k;
        }
    }
};