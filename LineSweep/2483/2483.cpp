#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:

    // 簡單題，數一數轉移一下cnt就可
    int bestClosingTime(string customers) 
    {
        int cntRightY = 0;
        int cntLeftN = 0;

        int n = customers.size();
        for (int i = n - 1; i >= 0; --i)
        {
            cntRightY += (customers[i] == 'Y');
        }

        int minCost = cntRightY;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            cntRightY -= (customers[i] == 'Y');
            if (cntLeftN + cntRightY < minCost)
            {
                minCost = cntLeftN + cntRightY;
                res = i + 1;
            }
            cntLeftN += (customers[i] == 'N');
        }

        return res;
    }
};