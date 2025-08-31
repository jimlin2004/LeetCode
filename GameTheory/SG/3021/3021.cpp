#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        一排每次只能拿一朵花，沒花拿輸
        -> 經典Nim game

        SG(0) = 0
        SG(1) = mex(SG(0)) = 1
        SG(2) = mex(SG(1)) = 0
        SG(3) = mex(SG(2)) = 1
        ...
        所以SG(n) = n mod 2

        因為有兩排
        所以要找 SG(n) mod 2 != SG(m) mod 2的n、m有幾種

        [1, 5]裡mod 2是 1 0 1 0 1 -> 2個0 3個1
        [1, 6]裡mod 2是 1 0 1 0 1 0 -> 3個0 3個1
        ->
        [1, n]裡mod 2 有 下高斯[n]個0, n - 下高斯[n]個1

        下方用O(n)的解法累加

        <注>官方解法有數學的O(1)方法 (可能不是SG)
    */
    long long flowerGame(int n, int m)
    {
        long long res = 0;

        // 迭代 1 ~ n
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 0) // m要找mod 2 == 1的
                res += m - (m / 2);
            else // m要找mod 2 == 0的
                res += m / 2;
        }

        return res;
    }
};