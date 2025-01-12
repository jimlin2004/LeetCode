#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool isPrefix(const string& str, const string& prefix)
    {
        if (str.size() < prefix.size())
            return false;
        int n = prefix.size();
        for (int i = 0; i < n; ++i)
        {
            if (str[i] != prefix[i])
                return false;
        }
        return true;
    }
    bool isSuffix(const string& str, const string& suffix)
    {
        if (str.size() < suffix.size())
            return false;
        int n = suffix.size();
        int j = str.size() - 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (str[j] != suffix[i])
                return false;
            --j;
        }
        return true;
    }
    //這題用暴搜就好，用Trie瘋了
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int res = 0;
        int n = words.size();
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (isPrefix(words[i], words[j]) && isSuffix(words[i], words[j]))
                    ++res;
            }
        }
        return res;
    }
};