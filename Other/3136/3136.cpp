#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    inline bool isVowel(char c)
    {
        c = tolower(c);
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }

    // 水題
    bool isValid(string word) 
    {
        int vowelCnt = 0;
        int consonantCnt = 0;

        bool ok = true;
        
        for (char c: word)
        {
            if (!isdigit(c) && !isalpha(c))
            {
                ok = false;
                break;
            }

            if (isVowel(c))
                ++vowelCnt;
            else if (isalpha(c))
                ++consonantCnt;
        }

        return ok && (word.size() >= 3) && (vowelCnt >= 1) && (consonantCnt >= 1);
    }
};