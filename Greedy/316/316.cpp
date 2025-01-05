#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //簡單題
    //就可以往前壓縮的就往前壓
    //算greedy
    string removeDuplicateLetters(string s) 
    {
        char res[10005];
        int len = 0;
        int cnt[300];
        bool used[300];
        
        memset(res, 0, sizeof(res));
        memset(used, 0, sizeof(used));

        for (char c: s)
            ++cnt[c];
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (used[s[i]])
            {
                --cnt[s[i]];
                continue;
            }
            while (len > 0 && res[len - 1] >= s[i] && cnt[res[len - 1]] > 0)
            {
                used[res[len - 1]] = false;
                --len;
            }
            res[len] = s[i];
            used[s[i]] = true;
            ++len;
            --cnt[s[i]];
        }
        string str = "";
        for (int i = 0; i < len; ++i)
            str += res[i];
        return str;
    }
};