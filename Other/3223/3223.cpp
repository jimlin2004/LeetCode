#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 直接統計字數然後推一下算法即可
    // 字的位置不重要，只要有3個一樣的字元
    // 就一定有中間一個可以消掉外面兩個
    /*
        aaa -> a
        aaaaa -> aa
        aaaaaa -> aa
        aaaaaaaaa -> a
    */
    int minimumLength(string s) 
    {
        int cnt[30];
        int n = s.size();
        for (int i = 0; i < n; ++i)
            ++cnt[s[i] - 'a'];
        int res = 0;
        for (int c = 0; c < 26; ++c)
        {
            // 推完後的算法
            while (cnt[c] >= 3)
            {
                int temp = cnt[c] / 3;
                cnt[c] = temp + (cnt[c] - 3 * temp);
            }
            res += cnt[c];
        }
        return res;
    }
};