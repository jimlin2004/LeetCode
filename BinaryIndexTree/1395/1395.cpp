#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:

    static const int maxr = 100005;

    int BITL[maxr];
    int BITR[maxr];

    int lowbit(int i)
    {
        return (i & -i);
    }

    void add(int BIT[], int i, int c)
    {
        while (i < maxr)
        {
            BIT[i] += c;
            i += lowbit(i);
        }
    }

    int sum(int BIT[], int i)
    {
        int res = 0;
        while (i > 0)
        {
            res += BIT[i];
            i -= lowbit(i);
        }
        return res;
    }

    int rsum(int BIT[], int l, int r)
    {
        return sum(BIT, r) - sum(BIT, l - 1);
    }

    // 用BIT去數左邊比我大的與比我小的
    // 還有右邊比我大的以及比我小的

    int numTeams(vector<int>& rating) 
    {
        for (int r: rating)
            add(BITR, r, 1);
        
        int res = 0;
        for (int r: rating)
        {
            int Ll = rsum(BITL, 0, r - 1);
            int Lg = rsum(BITL, r + 1, maxr - 1);
            int Rl = rsum(BITR, 0, r - 1);
            int Rg = rsum(BITR, r + 1, maxr - 1);

            res += Ll * Rg + Lg * Rl;

            add(BITL, r, 1);
            add(BITR, r, -1);
        }

        return res;
    }
};