#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    inline bool isVowel(char c)
    {
        return (c == 'a') || (c == 'e') || (c == 'i')
            || (c == 'o') || (c == 'u');
    }

    /*
        想一下就知道的題目
        如果有偶數的vowel，Alice可以拿走奇數個使剩下奇數的vowel，Bob輸
        有奇數個vowel，Alice可以全部拿走，此時Bob也輸
        所以Alice輸只有一種可能 -> 初始版面沒有vowel
    */
    bool doesAliceWin(string s)
    {
        bool hasVowel = false;
        for (char c: s)
        {
            if (isVowel(c))
            {
                hasVowel = true;
                break;
            }
        }

        return hasVowel; 
    }
};