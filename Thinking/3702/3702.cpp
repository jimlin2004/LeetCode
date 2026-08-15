#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        因為題目要subsequence
        且XOR裡XOR 0對結果無影響
        可以盡情XOR
        然後所有數字 x跟0做XOR就是x
        所以得到:

        如果整個陣列XOR != 0 -> 那整個陣列就是答案(n)
        如果整個陣列XOR = 0
            -> 如果都是0 -> 答案是0
            -> 如果有非0的數字 -> 答案就是任意拿掉一個非零的數字 -> n - 1
        所以只是一個腦筋急轉彎的題目
    */
    int longestSubsequence(vector<int>& nums)
    {
        int n = nums.size();

        int totalXOR = 0;
        bool allZero = true;
        for (int i = 0; i < n; ++i)
        {
            totalXOR ^= nums[i];
            if (nums[i] != 0)
                allZero = false;
        }

        if (totalXOR != 0)
            return n;
        
        if (totalXOR == 0)
        {
            if (allZero)
                return 0;
            return n - 1;
        }

        return -1;
    }
};