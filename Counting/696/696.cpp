#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // 因為題意，所以先算出每個0 / 1的group數量
    // 然後用min(cnts[i - 1], cnts[i])的方式加起來即可
    int countBinarySubstrings(string s)
    {
        vector<int> cnts;

        char prev = s[0];
        int currCnt = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (prev == s[i])
            {
                ++currCnt;
            }
            else
            {
                cnts.emplace_back(currCnt);
                prev = s[i];
                currCnt = 1;
            }
        }

        cnts.emplace_back(currCnt);

        int res = 0;
        for (int i = 1; i < cnts.size(); ++i)
        {
            res += min(cnts[i - 1], cnts[i]);
        }

        return res;
    }
};