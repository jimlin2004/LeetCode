#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 滑動窗戶水題，但要注意要求長度最短情況下字典序最小
    string shortestBeautifulSubstring(string s, int k)
    {
        string res = "";

        int l = 0, r = 0;
        int windowsCnt = 0;

        int n = s.size();

        while (r < n)
        {
            if (s[r] == '1')
                ++windowsCnt;
            while (windowsCnt == k && s[l] == '0')
                ++l;
            
            if (windowsCnt == k)
            {
                // 這時候會是當前最短的substring包含k個
                string substring = s.substr(l, r - l + 1);
                if (res.empty() || res.size() > substring.size())
                    res = substring;
                else if (res.size() == substring.size() && res > substring)
                    res = substring;
                
                // 位移l找下一個
                if (s[l] == '1')
                {
                    --windowsCnt;
                    ++l;
                }
            }

            ++r;
        }

        return res;
    }
};