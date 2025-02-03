#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    bool isArraySpecial(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            if ((nums[i - 1] & 1) == (nums[i] & 1))
                return false;
        }
        return true;
    }
};