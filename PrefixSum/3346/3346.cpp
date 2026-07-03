#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        因為可以挑numPoerations個數字 + [-k, k]
        所以很明顯的策略就是枚舉所有數字v當作想要變多的那個
        然後看看鄰居[v - k, v + k]可以有多少人來幫v

        為了做到這一點，明顯的需要用前綴和
    */
    int cnt[100005];
    int prefixSum[100005];

    inline int getRangeSum(int l, int r)
    {
        if (l == 0)
            return prefixSum[r];
        return prefixSum[r] - prefixSum[l - 1];
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int v: nums)
            ++cnt[v];
        
        prefixSum[0] = cnt[0];
        for (int i = 1; i < 100005; ++i)
            prefixSum[i] = prefixSum[i - 1] + cnt[i];
        
        int res = 0;
        for (int i = 0; i < 100005; ++i)
        {
            int neighborL = max(0, i - k);
            int neighborR = min(100004, i + k);

            // range sum記得要扣掉cnt[i]避免重複計算
            res = max(res, cnt[i] + min(getRangeSum(neighborL, neighborR) - cnt[i], numOperations));
        }

        return res;
    }
};