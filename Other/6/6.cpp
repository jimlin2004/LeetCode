#include <bits/stdc++.h>
using namespace std;

// 直接模擬 O(n ^ 2)
// 應該有規律可以用算的找答案，但我懶

class Solution 
{
public:
    string convert(string s, int numRows)
    {
        char table[1005][1005];
        memset(table, 0, sizeof(table));
        int r = 0;
        int rDir = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            table[r][i] = s[i];
            r += rDir;
            if (r == numRows - 1 || r == 0)
                rDir = -rDir;
        }

        string res = "";
        for (int i = 0; i < 1005; ++i)
        {
            for (int j = 0; j < 1005; ++j)
            {
                if (table[i][j])
                    res += table[i][j];
            }
        }
        return res;
    }
};