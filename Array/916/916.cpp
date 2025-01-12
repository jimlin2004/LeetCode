#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        int target[30];
        int curr[30];
        memset(target, 0, sizeof(target));
        // 所有的words2可以合成一個陣列看 -> 取每個字母要求最大的
        for (const string& word: words2)
        {
            memset(curr, 0, sizeof(curr));
            for (char c: word)
                ++curr[c - 'a'];
            for (int i = 0; i < 26; ++i)
                target[i] = max(target[i], curr[i]);
        }

        vector<string> res;
        for (const string& word: words1)
        {
            memset(curr, 0, sizeof(curr));
            // 掃一遍有哪些答案
            for (char c: word)
                ++curr[c - 'a'];
            // 檢查是否為universal
            bool ok = true;
            for (int i = 0; i < 26; ++i)
            {
                if (curr[i] < target[i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                res.emplace_back(word);
        }
        return res;
    }
};