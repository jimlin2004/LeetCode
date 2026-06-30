#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cnt[5];

    /*
        用滑動窗戶
        移動r新增字元
        然後如果abc都有了
        那就多了(s.size() - r)個子字串包含abc
        然後嘗試移動l找到新的substring起頭
        就能夠有更多答案
        O(n)
    */
    int numberOfSubstrings(string s)
    {
        memset(cnt, 0, sizeof(cnt));
        int typeCnt = 0;

        int n = s.size();

        int res = 0;
        int l = 0, r = 0;
        while (r < n)
        {
            if (cnt[s[r] - 'a'] == 0)
                ++typeCnt;
            ++cnt[s[r] - 'a'];
            while (typeCnt == 3)
            {
                res += (n - r);
                if (cnt[s[l] - 'a'] == 1)
                    --typeCnt;
                --cnt[s[l] - 'a'];
                ++l;
            }
            ++r;
        }

        return res;
    }
};