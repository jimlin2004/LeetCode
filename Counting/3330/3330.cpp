#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 數一下重複的就是答案
    int possibleStringCount(string word) 
    {
        int res = 1; // 原本字串算一個

        char prev = word[0];
        int currCnt = 1;
        for (int i = 1; i < word.size(); ++i)
        {
            if (prev == word[i])
                ++currCnt;
            else
            {
                res += currCnt - 1;
                currCnt = 1;
                prev = word[i];
            }
        }
        // 最後一個
        res += currCnt - 1;

        return res;
    }
};