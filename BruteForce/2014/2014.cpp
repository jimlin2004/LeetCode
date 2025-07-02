#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:

    /*
        最長的序列長度不會超過n / k
        且n < 8k(題目給定) -> n / k < 8
        可以證明最多不會有超過 [n / k]!個可能的字串
        每個字串需要O(n)檢查
        所以複雜度是O(n * [n / k]!)
        -> 2000 * 7! -> 10,080,000
    */

    bool check(const string& s, const string& seq, int k)
    {
        int cnt = 0; // 有幾個這樣的序列

        int ptr = 0;
        for (char c: s)
        {
            if (c == seq[ptr])
            {
                ++ptr;
                if (ptr == seq.size())
                {
                    ptr = 0;
                    ++cnt;
                    if (cnt == k)
                        return true;
                }
            }
        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) 
    {
        int freq[30];
        memset(freq, 0, sizeof(freq));

        // 統計char出現次數
        for (char c: s)
            ++freq[c - 'a'];
        
        vector<char> candidates; // 可能的字元(freq[c] >= k)
        // 為了字典序最大，所以用倒過來放的
        for (int c = 25; c >= 0; --c)
        {
            if (freq[c] >= k)
                candidates.push_back(c + 'a');
        }

        // 開始暴搜所有可能
        queue<string> q;
        for (char c: candidates)
            q.push(string(1, c));
        
        string res = "";

        while (!q.empty()) // 可能的字串長度不會超過 n / k
        {
            string curr = q.front();
            q.pop();
            if (curr.size() > res.size())
                res = curr;
            
            for (char c: candidates)
            {
                string nextPossible = curr + c;
                if (check(s, nextPossible, k))
                {
                    q.push(nextPossible);
                }
            }
        }

        return res;
    }
};