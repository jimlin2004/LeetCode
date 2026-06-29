#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f[105];

    void buildFail(const string& s)
    {
        f[0] = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            int j = f[i - 1];
            while (j > 0 && s[i] != s[j])
                j = f[j - 1];
            if (s[i] == s[j])
                ++j;
            f[i] = j;
        }
    }

    bool KMP(const string& text, const string& pattern)
    {
        buildFail(pattern);
        int i = 0;
        int j = 0;
        while (i < text.size())
        {
            if (text[i] == pattern[j])
            {
                ++i;
                ++j;

                if (j == pattern.size())
                    return true;
            }
            else
            {
                if (j == 0)
                    ++i;
                else if (j > 0)
                    j = f[j - 1];
            }
        }

        return false;
    }

    // KMP水題
    int numOfStrings(vector<string> &patterns, string word)
    {
        int res = 0;
        for (const string& pattern: patterns)
        {
            if (KMP(word, pattern))
                ++res;
        }

        return res;
    }
};

int main()
{
    vector<string> patterns = {"hvzoo","r","hyjcrgzr","yvqahvz","org","yvqahvz","org","oor","gxe","zo","ahvzoo","ahvzo","r","o","caviikty","pkxlcaams"};
    Solution S;
    S.numOfStrings(patterns, "tyvqahvzoorg");

    return 0;
}