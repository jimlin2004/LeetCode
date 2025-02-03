#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int n = nums.size();

        int maxInc = 1;
        int currInc = 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
                ++currInc;
            else
            {
                maxInc = max(maxInc, currInc);
                currInc = 1;
            }
        }
        maxInc = max(maxInc, currInc);

        int maxDec = 1;
        int currDec = 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
                ++currDec;
            else
            {
                maxDec = max(maxDec, currDec);
                currDec = 1;
            }
        }
        maxDec = max(maxDec, currDec);

        return max(maxInc, maxDec);
    }
};