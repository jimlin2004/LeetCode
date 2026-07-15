#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 水題
    int gcdOfOddEvenSums(int n)
    {
        int sumOdd = (1 + (n - 1) * 2 + 1) * n / 2;
        int sumEven = (2 + (n - 1) * 2 + 2) * n / 2;

        return gcd(sumOdd, sumEven);
    }
};