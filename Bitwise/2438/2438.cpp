#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    const long long MOD = 1000000007;

    /*
        數字 -> 2的冪次相加
        -> 想到二進位
        -> 用lowbit拆解n -> 二進位
        然後直接題目問多少就算多少
    */
    vector<int> productQueries(int n, vector<vector<int>>& queries)
    {
        vector<long long> powerOf2;
        while (n > 0)
        {
            int lowbit = (-n) & n;
            powerOf2.emplace_back(lowbit);
            n -= lowbit;
        }

        vector<int> res;

        for (auto& query: queries)
        {
            int prod = 1;
            for (int i = query[0]; i <= query[1]; ++i)
            {
                prod = (prod * (powerOf2[i] % MOD)) % MOD;
            }

            res.emplace_back(prod);
        }

        return res;
    }
};