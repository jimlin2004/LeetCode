#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // 水題
    int findClosest(int x, int y, int z)
    {
        int d1 = abs(x - z);
        int d2 = abs(y - z);
        if (d1 < d2)
            return 1;
        else if (d1 > d2)
            return 2;
        else
            return 0;
    }
};