#include <bits/stdc++.h>
using namespace std;


// KMP裸題
class Solution
{
private:
    int nextArr[10005];

    void buildNext(const string& s)
    {
        int n = s.size();
        nextArr[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            int j = nextArr[i - 1];
            while (j > 0 && s[i] != s[j])
                j = nextArr[j - 1];
            if (s[i] == s[j])
                ++j;
            nextArr[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle)
    {
        buildNext(needle);

        int i = 0, j = 0;
        while (i < haystack.size() && j < needle.size())
        {
            if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                if (j == 0)
                    ++i;
                else
                    j = nextArr[j - 1];
            }

            if (j == needle.size()) // 找到了
                return i - j;
        }

        return -1;
    }
};