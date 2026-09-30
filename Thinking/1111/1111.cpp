#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        題目的意思是要將括號字串分成A跟B兩個subsequence
        且max(depth(A), depth(B))要最小
        任何合法答案都可以

        所以直覺會想到對半拆
        比如
        (((()))) 會想用成
        01011010
        因此方法是用變數depth
        然後奇數depth時給A
        偶數depth給B
    */
    vector<int> maxDepthAfterSplit(string seq) 
    {
        int n = seq.size();
        vector<int> res(n);

        int depth = 0;
        for (int i = 0; i < n; ++i)
        {
            if (seq[i] == '(')
                res[i] = (depth++) % 2; // 深度後面變深
            else
                res[i] = (--depth) % 2; // 深度先變淺
        }

        return res;
    }
};