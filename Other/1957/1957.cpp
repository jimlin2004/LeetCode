#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    string makeFancyString(string s) 
    {
        char prev = '\0';
        int cnt = 1;

        string res = "";

        for (char ch: s)
        {
            if (ch == prev)
                ++cnt;
            else
                cnt = 1;
            
            if (cnt < 3)
                res += ch;
            
            prev = ch;
        }

        return res;
    }
};