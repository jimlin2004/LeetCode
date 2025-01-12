#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void buildNext(int nextArr[], const string& s)
    {
        int len = s.size();
        nextArr[0] = 0;
        for (int i = 1; i < len; ++i)
        {
            int j = nextArr[i - 1];
            while (j > 0 && s[i] != s[j])
                j = nextArr[j - 1];
            if (s[i] == s[j])
                ++j;
            nextArr[i] = j;
        }
    }

    bool contain(const string& s, const string& pattern)
    {
        static int nextArr[35];
        buildNext(nextArr, s);
        int i = 0;
        int j = 0;
        while (i < s.size() && j < pattern.size())
        {
            if (s[i] == pattern[j])
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
        }
        return j == pattern.size();
    }

    // 砸KMP就對了
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> res;
        int n = words.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                if (words[i].size() <= words[j].size())
                {
                    if (contain(words[j], words[i]))
                    {
                        res.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<string> input = {"leetcode", "et", "code"};
    Solution s;
    s.stringMatching(input);
    return 0;
}