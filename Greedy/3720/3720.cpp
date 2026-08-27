#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 要將s排列比target大一點
    // 直覺: 先讓s變得跟target一樣，後面往回找第一個可以變大的點，然後後續直接由小到大填字母
    string lexGreaterPermutation(string s, string target) 
    {
        vector<int> cnts(300, 0);

        for (char ch: s)
            ++cnts[ch];
        
        int n = s.size();

        int matchLen = 0; // 先跟target用一樣的字
        while (matchLen < n && cnts[target[matchLen]] > 0)
        {
            --cnts[target[matchLen]];
            ++matchLen;
        }

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
                string res = target.substr(0, i); // 前面跟target一樣
                // 第一個變大的字
                res += nextChar;
                --cnts[nextChar];
                // 剩下的字由小到大填可以保證比target大一點
                for (int ch = 'a'; ch <= 'z'; ++ch)
                {
                    while (cnts[ch] > 0)
                    {
                        res += ch;
                        --cnts[ch];
                    }
                }

                return res;
            }
        }

        // 沒有答案
        return "";
    }
};