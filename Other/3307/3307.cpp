#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 字串太長
    // 改用算的
    char kthCharacter(long long k, vector<int>& operations) 
    {
        vector<long long> history; // 記下每次操作時的長度
        long long currLen = 1;
        while (currLen < k)
        {
            currLen *= 2;
            history.push_back(currLen);
        }

        int shift = 0; // 位移的次數
        for (int i = history.size() - 1; i >= 0; --i)
        {
            long long prevLen = history[i] / 2; // 這次操作前的長度
            // 如果k是在前一個操作的前半段
            // k不變
            // 如果在後半段
            // k -= prevLen即可得到原本從哪來的長度
            if (k > prevLen)
            {
                k -= prevLen;
                if (operations[i] == 1)
                    ++shift;
            }
        }

        return (shift) % 26 + 'a';
    }
};