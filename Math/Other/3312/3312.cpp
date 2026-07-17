#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        求所有(nums[i], nums[j])的gcd排序後sortedGCD[]
        然後回答所有sortedGCD[queries[i]]

        解法參考題解，細節看下方
    */
    static const int maxVal = 50000;

    int cnt[maxVal + 5];
    int cntG[maxVal + 5];
    int prefix[maxVal + 5];

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries)
    {
        /*
            因為枚舉所有pair需要O(N^2)，時間會過不了
            但是因為nums的值域在 [1, 50000]，
            且gcd(nums[i], nums[j]) in [1, 50000]
            所以要對gcd的值下手
            目標是統計出gcd(A, B)是g的倍數有多少個
            因為gcd(A, B)是g的倍數，此時A、B都是g的倍數

            作法是先統計nums的數字出現多少次
        */
        memset(cnt, 0, sizeof(cnt));
        for (int val: nums)
            ++cnt[val];
        /*
            得到cnt[]後，統計整個陣列中有多少數字是g的倍數
            也就是
            v = \sum_{g | x} cnt[x]
        */
        for (int g = 1; g <= maxVal; ++g)
        {
            long long v = 0;
            for (int j = g; j <= maxVal; j += g)
            {
                v += cnt[j];
            }

            /*
                然後在這v個數字中，任意選兩個數字，gcd都一定是g
                因此配對數就是C^n_2
            */
            cntG[g] = v * (v - 1) / 2;
        }

        /*
            至此numOfPairsWithMultiple[g]裡面的值是g、2g、3g、4g...的配對數
            為了得到精確的gcd是g的配對數cntG[g]
            作法是從大到小反向遍歷
            將多餘的配對數扣除

            cntG[g] = cnt[g] - \sum_{k = 2}^{下高斯[M / g]} cntG[k * g]

            這裡的數學原理是
            定義
            S(g)是所有gcd=g的倍數的配對集合
            E(g)是所有gcd剛好是g的配對集合
            因此
            S(g) = E(g) ∪ E(2g) ∪ E(3g) ∪ ...
            其中的數量關係是
            |S(g)| = |E(g)| + |E(2g)| + |E(3g)| + ...
            移項
            |E(g)| = |S(g)| - (|E(2g)| + |E(3g)| + ...)
            透過反向由大的g開始計算(因為一開始只有S(maxVal)是E(maxVal))
            就能讓整個cntG[g]變成精確的E(1), E(2), E(3), ...
        */
        for (int g = maxVal; g >= 1; --g)
        {
            for (int mult = g * 2; mult <= maxVal; mult += g)
            {
                cntG[g] -= cntG[mult];
            }
        }

        /*
            為了加速搜尋答案
            在最後利用前綴和 + 二分搜
        */
        prefix[0] = 0;
        for (int i = 1; i<= maxVal; ++i)
            prefix[i] = prefix[i - 1] + cntG[i];
        
        vector<int> res;
        for (int q: queries)
        {
            // 要用upper_bound才會對
            auto it = upper_bound(prefix + 1, prefix + maxVal + 1, q);
            res.emplace_back(it - prefix);
        }

        return res;
    }
};