#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    inline bool isVowel(char c)
    {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }

    //基本前綴和
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        int prefix[100005];
        prefix[0] = 0;
        for (int i = 1; i <= words.size(); ++i)
            prefix[i] = prefix[i - 1] + (isVowel(words[i - 1][0]) && isVowel(words[i - 1].back()));
        vector<int> res;
        for (auto& query: queries)
            res.emplace_back(prefix[query[1] + 1] - prefix[query[0] + 1 - 1]);
        return res;
    }
};