#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:

    int getDigitalSum(int n)
    {
        int res = 0;
        while (n > 0)
        {
            res += n % 10;
            n /= 10;
        }

        return res;
    }

    // 水題
    int smallestIndex(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (i == getDigitalSum(nums[i]))
                return i;
        }

        return -1;
    }
};