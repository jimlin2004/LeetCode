#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        題目意思是指s = a + b + c + d + ...
        然後a、b、c、d...彼此是排列關係
        問最短a、b、c、d...的長度是?

        枚舉所有答案，因為答案一定是|s|的因數
        所以枚舉所有因數看看
    */

    inline vector<int> getFreqVec(string_view s)
    {
        vector<int> cnt(26, 0);
        for (char c: s)
            ++cnt[c - 'a'];
        return cnt;
    }

    bool check(string_view s, int len)
    {
        vector<int> first = getFreqVec(s.substr(0, len));
        for (int i = len; i < s.size(); i += len)
        {
            if (first != getFreqVec(s.substr(i, len)))
                return false;
        }

        return true;
    }

    int minAnagramLength(string s) 
    {
        int res = -1;

        long long n = s.size();

        for (long long i = 1; i <= n; ++i)
        {
            if (n % i == 0)
            {
                if (check(s, i))
                {
                    res = i;
                    break;
                }
            }
        }

        if (res == -1)
        {
            res = s.size(); // 因數找不到，答案就是自己
        }

        return res;
    }
};