#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

class Solution 
{
public:
    long long prefix[maxn];
    long long suffix[maxn];

    /*
        計算prefix[i] -> 讓0 ~ i - 1變成s[i]的成本
        suffix[i] -> 讓n - 1 ~ i + 1變成s[i]的成本
        然後枚舉i作為中繼點，因為答案一定是s[i]不用動的情況
        找最少的prefix[i] + suffix[i]
    */
    long long minimumCost(string s)
    {
        int n = s.size();

        prefix[0] = 0;
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + (s[i] != s[i - 1] ? i : 0);
        
        suffix[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i)
            suffix[i] = suffix[i + 1] + (s[i] != s[i + 1] ? n - 1 - i : 0);
        
        long long res = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0; i < n; ++i)
            res = min(res, prefix[i] + suffix[i]);
        return res;
    }
};

int main()
{
    Solution S;
    S.minimumCost("0011");
    return 0;
}