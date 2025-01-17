#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string mergeAlternately(string word1, string word2) 
    {
        string res = "";
        int i = 0, j = 0;
        int n = word1.size();
        int m = word2.size();
        while (i < n && j < m)
        {
            res += word1[i];
            res += word2[j];
            ++i, ++j;
        }
        while (i < n)
        {
            res += word1[i];
            ++i;
        }
        while (j < m)
        {
            res += word2[j];
            ++j;
        }
        return res;
    }
};