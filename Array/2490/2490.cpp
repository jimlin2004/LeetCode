#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    bool isCircularSentence(string sentence) 
    {
        string_view sentence_view(sentence);
        auto words = sentence_view | views::split(' ')
                    | ranges::to<vector<string>>();
        bool ok = true;

        int n = words.size();
        for (int i = 0; i < n; ++i)
        {
            if (words[i].back() != words[(i + 1) % n][0])
            {
                ok = false;
                break;
            }
        }

        return ok;
    }
};