#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 用stack知道要移掉哪個字即可
    string clearDigits(string s) 
    {
        stack<int> sk;
        bool removed[105];
        memset(removed, 0, sizeof(removed));

        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                if (!sk.empty())
                {
                    removed[sk.top()] = true;
                    sk.pop();
                }
                removed[i] = true;
            }
            else
                sk.push(i);
        }

        string res = "";
        for (int i = 0; i < n; ++i)
        {
            if (!removed[i])
                res += s[i];
        }
        return res;
    }
};