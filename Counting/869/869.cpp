#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        第一個想法是暴力的用next_permutation去檢查是否是2的冪次
        更快的解法:
            由於數字可以隨意排(無前導0個情況下)
            所以只要檢查n的各digit的freq是否跟某個2的冪次一樣即可
    */
    bool reorderedPowerOf2(int n) 
    {
        // 當前n轉成各digit的freq
        vector<int> freq(10, 0);
        while (n)
        {
            ++freq[n % 10];
            n /= 10;
        }
        
        for (long long val = 1; val <= 1000000000LL; val <<= 1)
        {
            vector<int> powerOf2Freq(10, 0);

            long long curr = val;

            while (curr)
            {
                ++powerOf2Freq[curr % 10];
                curr /= 10;
            }

            if (freq == powerOf2Freq)
                return true;
        }

        return false;
    }
};