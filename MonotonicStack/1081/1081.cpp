#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        題目要包含所有字元種類的最小字典序子序列

        基本上就是想辦法讓字串變小
        所以使用monotonic stack處理字串
        如果現在的字比sk的小且sk的字在後面還有
        那我就不需要那些字元，可以拿掉
        另外就是因為sk是單調上升的，所以如果現在的字元
        已經在sk中，那我們也不需要這個新的字(因為原本的那個字已經在sk正確的位置)
    */
    string smallestSubsequence(string s)
    {
        vector<int> cnt(300, 0);
        for (char c: s)
            ++cnt[c];
        
        // string當stack用
        string sk;
        vector<bool> inStack(300, false);
        for (char c: s)
        {
            if (!inStack[c])
            {
                while (!sk.empty() && sk.back() >= c && cnt[sk.back()] > 0)
                {
                    inStack[sk.back()] = false;
                    sk.pop_back();
                }
                sk.push_back(c);
                inStack[c] = true;
            }
            --cnt[c];
        }

        return sk;
    }
};