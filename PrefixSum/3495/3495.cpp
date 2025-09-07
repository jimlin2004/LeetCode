#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // 求 1 ~ end總共需要多少操作次數
    long long prefixSum(long long end)
    {
        long long res = 0;
        long long opCnt = 1; // 目前的數字需要除多少次

        long long curr = 1;

        while (curr < end)
        {
            long long r = min(curr * 4 - 1, end);
            res += (r - curr + 1) * opCnt;

            ++opCnt; // 下一次的數字需要更多一次操作次數
            curr *= 4;
        }

        if (curr == end) // 最後一個數字特別處理
            res += opCnt;

        return res;
    }

    /*
        首先
        1 ~ 3   需要1次操作
        4 ~ 15  需要2次操作
        16 ~ 63 需要3次操作
        ...

        因此利用分塊的想法我們能夠在 O(log4(n)) 計算出 1 ~ n的數列中操作次數總和為多少
        同時每次可以挑兩個數字處理，所以1 ~ n裡總共只需要 操作次數總和 / 2輪就能做完

        能計算出1 ~ n就能用前綴和的方式計算出 l ~ r的操作次數

        所以只需要 O(n log4(maxN)) 即可，maxN是詢問最大數字範圍
    */
    long long minOperations(vector<vector<int>>& queries)
    {
        long long res = 0;

        for (auto& query: queries)
        {
            // 要ceil，因為奇數個要多一次
            res += (long long)ceil( (prefixSum(query[1]) - prefixSum(query[0] - 1)) / 2.0 );
        }

        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> q = {{1, 2}, {2, 4}};
    S.minOperations(q);

    return 0;
}