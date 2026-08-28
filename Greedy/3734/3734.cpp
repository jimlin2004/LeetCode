#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        這題跟3720有關，只是變成答案要是s的排列且迴文
        細節看下方
        (就是3720多一些考慮的延伸題)
    */
    string lexPalindromicPermutation(string s, string target)
    {
        // 先檢查s能不能變成迴文
        // 1. 只有一個奇數的字母
        // 2. 都是偶數的字母
        vector<int> cnts(300, 0);

        for (char ch: s)
            ++cnts[ch];

        char midChar = '\0';
        int oddCnt = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            if (cnts[ch] & 1)
            {
                midChar = ch;
                ++oddCnt;
            }
        }

        if (oddCnt > 1)
            return ""; // 湊不出迴文
        
        /*
            因為最終要將s變成迴文
            所以可以當作建構前半字串，後半倒過來接即可
            為了方便，先將所有字母 / 2
            同時奇數也會被很好處理，比如3個，3 / 2 = 1 -> 剛好前半能放一個，後半放一個，剩下一個在中間
        */
        for (char ch = 'a'; ch <= 'z'; ++ch)
            cnts[ch] /= 2;

        /*
            開始用到3720的技巧
            要讓s比target大一點，首先讓s盡量跟target一樣，最後往回找到第一個可以變大的點，然後後續直接由小到大填字母
            但是這題是回文
            多一種可能就是前半完全等於target，是因為前半 + 後半可能比target
            這時候這一種可能就會是比target大一點的答案(字典序最小)
            否則就回到3720的解法
        */

        int n = s.size() / 2;
        int matchLen = 0; // 先跟target用一樣的字
        while (matchLen < n && cnts[target[matchLen]] > 0)
        {
            --cnts[target[matchLen]];
            ++matchLen;
        }

        // 如果前半可以跟target完全一樣
        // 就試試看第一種情況
        if (matchLen == n)
        {
            string prefix = target.substr(0, matchLen);
            string suffix(prefix.rbegin(), prefix.rend());

            string candidate;
            if (midChar != '\0')
            {
                candidate = prefix + midChar + suffix;
                if (candidate > target)
                    return candidate;
            }
            else
            {
                candidate = prefix + suffix;
                if (candidate > target)
                    return candidate;
            }
        }

        // 回到3720的解法
        // 往回找第一個可以變大的點
        // 用min是因為可能剛好matchLen完整配到底，但我們要嚴格大於target
        for (int i = min(matchLen, n - 1); i >= 0; --i)
        {
            // 先將這個字拿掉
            if (i < matchLen) // 因為可能matchLen == n，這時候target[i]不存在
                ++cnts[target[i]];
            
            // 試試看將這個字變大一點
            char nextChar = '\0';
            for (char ch = target[i] + 1; ch <= 'z'; ++ch)
            {
                if (cnts[ch] > 0)
                {
                    nextChar = ch;
                    break;
                }
            }

            // 找到第一個變大的點
            if (nextChar != '\0')
            {
                string prefix = target.substr(0, i); // 前面跟target一樣
                // 第一個變大的字
                prefix += nextChar;
                --cnts[nextChar];
                // 剩下的字由小到大填可以保證比target大一點
                for (int ch = 'a'; ch <= 'z'; ++ch)
                {
                    while (cnts[ch] > 0)
                    {
                        prefix += ch;
                        --cnts[ch];
                    }
                }

                string suffix(prefix.rbegin(), prefix.rend());

                if (midChar != '\0')
                    return prefix + midChar + suffix;
                else
                    return prefix + suffix;
            }
        }

        // 沒有答案
        return "";
    }
};