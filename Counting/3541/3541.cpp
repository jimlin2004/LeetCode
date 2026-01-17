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

    // 水題
    int maxFreqSum(string s)
    {
        int cnt[300];
        memset(cnt, 0, sizeof(cnt));

        int vowelFreq = 0;
        int consonantFreq = 0;

        for (char c: s)
        {
            ++cnt[c];
            if (isVowel(c))
                vowelFreq = max(vowelFreq, cnt[c]);
            else
                consonantFreq = max(consonantFreq, cnt[c]);
        }

        return vowelFreq + consonantFreq;
    }
};