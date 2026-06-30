#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBroken[300];

    int canBeTypedWords(string text, string brokenLetters)
    {
        memset(isBroken, 0, sizeof(isBroken));
        for (char c: brokenLetters)
            isBroken[c] = true;

        int res = 0;

        for (auto word: text | views::split(' '))
        {
            bool ok = true;

            for (char c: word)
            {
                if (isBroken[c])
                {
                    ok = false;
                    break;
                }
            }

            res += ok;
        }

        return res;
    }
};