#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 水題
    int minimumChairs(string s)
    {
        int res = 0;
        int curr = 0;
        for (char c: s)
        {
            if (c == 'E')
                ++curr;
            else
                --curr;
            res = max(res, curr);
        }

        return res;
    }
};