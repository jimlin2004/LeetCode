#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 不知道出來幹嘛的水題
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        vector<string> A;
        vector<string> B;

        int n = words.size();
        int target = 0;
        for (int i = 0; i < n; ++i)
        {
            if (groups[i] == target)
            {
                A.push_back(words[i]);
                target = 1 - target;
            }
        }

        target = 1;
        for (int i = 0; i < n; ++i)
        {
            if (groups[i] == target)
            {
                B.push_back(words[i]);
                target = 1 - target;
            }
        }

        return (A.size() > B.size()) ? A : B;
    }
};