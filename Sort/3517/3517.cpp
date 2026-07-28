#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        因為輸入是迴文
        輸出也要是排序後的迴文
        所以只要對半邊做sort即可
    */
    // 因為是字串，所以用counting sort
    string countingSort(const string& s)
    {
        vector<int> cnt(300, 0);
        for (char c: s)
            ++cnt[c];
        for (int i = 1; i < 300; ++i)
            cnt[i] += cnt[i - 1];
        string res(s);
        for (int i = s.size() - 1; i >= 0; --i)
        {
            res[cnt[s[i]] - 1] = s[i];
            --cnt[s[i]];
        }
        return res;
    }

    string smallestPalindrome(string s) 
    {
        int halfLen = s.size() / 2;
        string middle = (s.size() % 2 == 1) ? string(1, s[halfLen]) : "";

        string sortedLeftString = countingSort(s.substr(0, halfLen));
        string sortedRightString(sortedLeftString);
        reverse(sortedRightString.begin(), sortedRightString.end());

        return sortedLeftString + middle + sortedRightString;
    }
};