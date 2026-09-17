#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        題意:
            在array中找兩個non-overlapping的subarray，且那兩個subarray各自的和 == target
            並且要求兩個subarray加起來長度要最短

        看著挺難的，但其實就是滑動窗戶的變體
        因為array都是正整數，所以可以滑動窗戶找到最短長度
        所以另外用一個minLen[i]去紀錄到i為止最短的長度
        這樣每次用滑動窗戶找到l ~ r是一個區間時
        可以找到一個候選解 minLen[l - 1] + (r - l + 1)
    */
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        int n = arr.size();

        vector<int> minLen(n, 0x3f3f3f3f);

        int res = 0x3f3f3f3f;

        int windowSum = 0;
        int l = 0, r = 0;
        while (r < n)
        {
            windowSum += arr[r];
            while (windowSum > target)
            {
                windowSum -= arr[l];
                ++l;
            }

            if (r > 0)
                minLen[r] = minLen[r - 1]; // 繼承之前最好答案

            if (windowSum == target)
            {
                int currLen = r - l + 1;
                if (l - 1 >= 0 && minLen[l - 1] < 0x3f3f3f3f)
                    res = min(res, minLen[l - 1] + currLen);
                
                minLen[r] = min(minLen[r], currLen); // 更新最好答案
            }

            ++r;
        }

        return (res < 0x3f3f3f3f) ? res : -1;
    }
};