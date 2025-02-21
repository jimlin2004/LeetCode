#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(string& res, int& cnt,int n, int k, int index)
    {
        if (index == n)
        {
            ++cnt;
            return cnt == k;
        }
        for (char c = 'a'; c <= 'c'; ++c )
        {
            if (res[index - 1] == c)
                continue;
            res[index] = c;
            if (dfs(res, cnt, n, k, index + 1))
                return true;
        }
        return false;
    }

    // 就暴搜
    string getHappyString(int n, int k)
    {
        string res;
        res.resize(n);
        int cnt = 0;
        // 第一個字額外處理
        for (char c = 'a'; c <= 'c'; ++c)
        {
            res[0] = c;
            if (dfs(res, cnt, n, k, 1))
                break;
        }
        if (cnt != k)
            return "";
        return res;
    }
};