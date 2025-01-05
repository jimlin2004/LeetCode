#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    inline char asciiShift(char c, int shift)
    {
        static int start = 'a';
        int normailzedShift = (shift % 26 + 26) % 26; //處理負數
        return (char)((c - start + normailzedShift) % 26 + start); 
    }

    // 用差分處理區間加值
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        // 差分陣列
        int diff[50005];
        // 建差分陣列
        int n = s.size();
        diff[0] = s[0] - 'a';
        for (int i = 1; i < n; ++i)
            diff[i] = s[i] - s[i - 1];
        for (auto& shift: shifts)
        {
            if (shift[2] == 1)
            {
                diff[shift[0]] += 1;
                diff[shift[1] + 1] -= 1;
            }
            else
            {
                diff[shift[0]] -= 1;
                diff[shift[1] + 1] += 1;
            }
        }
        // 反推回字串
        string res = "";
        res += asciiShift('a', diff[0]);
        for (int i = 1; i < n; ++i)
        {
            res += asciiShift(res.back(), diff[i]);
        }
        return res;
    }
};