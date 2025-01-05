#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //要有技巧的枚舉
    //O(n)且要求回文長度3->想到枚舉中間
    //需要left[]、right[]的幫助，然後left[]、right[]的轉移很簡單
    int countPalindromicSubsequence(string s) 
    {
        bool used[30][30]; //used[a][b] -> 字元aba被算過了
        int right[30]; //從index 0開始數，每個字元有幾個
        int left[30]; //到index 0為止，每個字元有幾個
        memset(used, 0, sizeof(used));
        memset(right, 0, sizeof(right));
        memset(left, 0, sizeof(left));
        int n = s.size();
        for (int i = 0; i < n; ++i)
            ++right[s[i] - 'a'];
        int res = 0;
        //枚舉中間的字
        for (int i = 0; i < n; ++i)
        {
            int currChar = s[i] - 'a';
            //right轉移到現在的位置
            --right[currChar];
            //枚舉所有可能的字母 -> 只有26種，所以可以當作O(26n) -> O(n)
            for (int c = 0; c < 26; ++c)
            {
                if (left[c] && right[c] && !used[c][currChar])
                {
                    ++res;
                    used[c][currChar] = true;
                }
            }
            //轉移left到下個位置
            ++left[currChar];
        }
        return res;
    }
};