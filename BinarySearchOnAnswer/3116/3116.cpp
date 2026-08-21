#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        題意:
            有coins種無限硬幣，不能兩種硬幣組合，問第k小可以湊出來的面額
            然後因為k很大
            所以又是經典 二分搜 + 排容原理
    */

    // 排容原理數有1 ~ mid有多少數字被coins中的數字整除
    long long countMultiples(long long mid, const vector<int>& coins)
    {
        int n = coins.size();
        long long total = 0;

        // 排容原理枚舉所有組合
        // 用bitset
        for (int mask = 1; mask < (1 << n); ++mask)
        {
            long long currLCM = 1;
            int bitCnt = 0;

            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                {
                    ++bitCnt;
                    currLCM = lcm(currLCM, coins[i]);
                }
            }

            long long cnt = mid / currLCM;
            if (bitCnt & 1) // 奇數種coins在排容用加的
                total += cnt; // 偶數種coins在排容用減的
            else
                total -= cnt;
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k)
    {
        long long l = 0;
        long long r = *max_element(coins.begin(), coins.end()) * (long long)k;

        while (l + 1 < r)
        {
            long long mid = l + ((r - l) >> 1);
            if (countMultiples(mid, coins) < k)
                l = mid;
            else
                r = mid;
        }

        return r;
    }
};