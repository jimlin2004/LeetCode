#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // greedy的題目
    // 因為只要求最多位數而不要求大小(只要 <= k)
    // 所以用慢慢append的方式維護目前的值
    // 當現在的值太大的時候就將最左邊的bit 1變成0再append新的bit
    // 可以保證長度單調上升，不會變短
    // 且k不會是0，所以可以直接用log找最左邊的bit 1
    int longestSubsequence(string s, int k) 
    {
        int curr = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (((curr << 1) | (s[i] - '0')) > k)
            {
                int leftOne = 1 << ((int)floor(log2(curr)));
                curr ^= leftOne; // 最高位的1去掉
                curr = ((curr << 1) | (s[i] - '0'));
            }
            else
            {
                ++res;
                curr = ((curr << 1) | (s[i] - '0'));
            }
        }

        return res;
    }
};

int main()
{
    Solution S;
    S.longestSubsequence("1001010", 5);
    return 0;
}