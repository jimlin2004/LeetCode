#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int reverseDegree(string s) 
    {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            res += ('z' - s[i] + 1) * (i + 1);
        }

        return res;
    }
};