#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool dfs(int index, bool used[], string& res, const string& pattern)
    {
        if (index == pattern.size())
            return true;
        for (int i = '1'; i <= '9'; ++i)
        {
            if (used[i - '0'])
                continue;
            if (pattern[index] == 'I')
            {
                if (res[index - 1] < i)
                {
                    res[index] = i;
                    used[i - '0'] = true;
                    if (dfs(index + 1, used, res, pattern))
                        return true;
                    used[i - '0'] = false;
                    res[index] = 0;
                }
            }
            else // 'D'
            {
                if (res[index - 1] > i)
                {
                    res[index] = i;
                    used[i - '0'] = true;
                    if (dfs(index + 1, used, res, pattern))
                        return true;
                    used[i - '0'] = false;
                    res[index] = 0;
                }
            }
        }
        return false;
    }

    // 直接backtracking暴搜可能的答案，光速下課
    string smallestNumber(string pattern) 
    {
        // pattern向右移一格
        pattern = 'z' + pattern;
        string res;
        res.resize(pattern.size());
        
        bool used[15];
        memset(used, 0, sizeof(used));
        // 第一層分開處理
        for (int i = '1'; i <= '9'; ++i)
        {
            res[0] = i;
            used[i - '0'] = true;
            if (dfs(1, used, res, pattern))
                break;
            used[i - '0'] = false;
        }
        return res;
    }
};