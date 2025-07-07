#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:

    int BIT[20005];

    inline int lowbit(int x)
    {
        return x & -x;
    }

    void add(int i, int c)
    {
        while (i < 20005)
        {
            BIT[i] += c;
            i += lowbit(i);
        }
    }

    int getSum(int i)
    {
        int res = 0;
        while (i > 0)
        {
            res += BIT[i];
            i -= lowbit(i);
        }

        return res;
    }

    int getRangeSum(int a, int b)
    {
        return getSum(b) - getSum(a - 1);
    }

    // BIT秒解
    // 用值域建BIT，求0 ~ currVal - 1有多少數字即可
    vector<int> countSmaller(vector<int>& nums) 
    {
        // 為了處理負數，所以都先加上10001(不能是10000，BIT不好處理0)
        int shift = 10001;

        int n = nums.size();
        memset(BIT, 0, sizeof(BIT));

        vector<int> res(n, 0);
        // 倒過來做，就能很好處理只看右邊的限制
        for (int i = n - 1; i >= 0; --i)
        {
            int currVal = nums[i] + shift;
            res[i] = getRangeSum(0, currVal - 1);
            add(currVal, 1);
        }

        return res;
    }
};