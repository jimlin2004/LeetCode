#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        如果偶數 -> 開始填 i跟-i，i每次遞增
        如果奇數 -> 先填一個0，變成偶數
    */
    vector<int> sumZero(int n) 
    {
        vector<int> res;

        if (n & 1)
        {
            res.emplace_back(0);
            --n;
        }
        
        for (int i = 1; res.size() < n; ++i)
        {
            res.emplace_back(i);
            res.emplace_back(-i);
        }

        return res;
    }
};