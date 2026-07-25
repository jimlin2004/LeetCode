#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 水題
    int maxProduct(int n)
    {
        int max1 = 0;
        int max2 = 0;
        while (n > 0)
        {
            int val = n % 10;
            n /= 10;
            if (val > max1)
            {
                max2 = max1;
                max1 = val;
            }
            else if (val > max2)
            {
                max2 = val;
            }
        }

        return max1 * max2;
    }
};