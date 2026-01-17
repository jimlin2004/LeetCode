#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    inline bool isVowel(char c)
    {
        return (c == 'A') || (c == 'a') || (c == 'E') || (c == 'e')
                || (c == 'I') || (c == 'i') || (c == 'O') || (c == 'o')
                || (c == 'U') || (c == 'u');
    }

    /*
        簡單sort題
        可以counting sort
        但是懶
    */
    string sortVowels(string s)
    {
        string res(s);
        int n = s.size();

        vector<char> vowels;

        for (char c: s)
        {
            if (isVowel(c))
                vowels.emplace_back(c);
        }

        sort(vowels.begin(), vowels.end());

        auto vowelIter = vowels.begin();
        for (int i = 0; i < n; ++i)
        {
            if (isVowel(res[i]))
            {
                res[i] = *vowelIter;
                ++vowelIter;
            }
        }

        return res;
    }
};