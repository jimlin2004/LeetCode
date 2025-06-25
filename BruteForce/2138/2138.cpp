#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 水題
    vector<string> divideString(string s, int k, char fill) 
    {
        int n = s.size();

        vector<string> res;
        for (int i = 0; i < n - (n % k); i += k)
        {
            string curr = "";
            for (int j = i; j < i + k; ++j)
            {
                curr += s[j];
            }
            res.push_back(curr);
        }

        if (n % k != 0)
        {
            string curr = "";
            for (int i = n - (n % k); i < n; ++i)
            {
                curr += s[i];
            }
            for (int i = 0; i < k - (n % k); ++i)
            {
                curr += fill;
            }
            res.push_back(curr);
        }

        return res;
    }
};