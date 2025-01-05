#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //基本前綴和運用，其實可以維護左邊與右邊的0跟1數量即可(轉移很簡單)
    int maxScore(string s) 
    {
        int prefix_0[505];
        int prefix_1[505];
        prefix_0[0] = 0;
        prefix_1[0] = 0;
        int n = s.size();
        for (int i = 1; i <= n; ++i)
        {
            prefix_0[i] = prefix_0[i - 1] + (s[i - 1] == '0');
            prefix_1[i] = prefix_1[i - 1] + (s[i - 1] == '1');
        }
        int res = 0;
        for (int i = 1; i < n; ++i)
            res = max(res, prefix_0[i] + (prefix_1[n] - prefix_1[i]));
        return res;
    }
};