#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // 水題
    string largestGoodInteger(string num)
    {
        string res = "";

        int n = num.size();

        for (int i = 2; i < n; ++i)
        {
            string substring = num.substr(i - 2, 3);
            if (substring[0] == substring[1] && substring[1] == substring[2])
            {
                if (res < substring)
                    res = substring;
            }
        }

        return res;
    }
};