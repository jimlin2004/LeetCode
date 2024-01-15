#include <bits/stdc++.h>
using namespace std;

//O(t.size())

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int sPtr = 0;
        for (int tPtr = 0; tPtr < t.size(); ++tPtr)
        {
            if (s[sPtr] == t[tPtr])
                ++sPtr;
        }
        return (sPtr == s.size());
    }
};