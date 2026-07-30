#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題?
    // 但解答是數學解
    int minimumPushes(string word) 
    {
        int cnt[300];
        memset(cnt, 0, sizeof(cnt));

        for (char c: word)
            ++cnt[c];

        vector<int> allFreq;
        for (char i = 'a'; i <= 'z'; ++i)
        {
            if (cnt[i] > 0)
                allFreq.emplace_back(cnt[i]);
        }

        sort(allFreq.begin(), allFreq.end(), [](int a, int b){
            return a > b;
        });

        int currBtn = 0; // 現在用到第幾個按鍵，總共只有8個按鍵
        int currNeed = 1; // 現在還只需要按幾次

        int total = 0;
        for (int freq: allFreq)
        {
            ++currBtn;
            total += freq * currNeed;
            if (currBtn == 8)
            {
                currBtn = 0;
                ++currNeed;
            }
        }

        return total;
    }
};