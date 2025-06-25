#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 水題，sort後雙指標
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int res = 1; // 原本就算一次
        int l = 0, r = 0;
        while (r < n)
        {
            if (nums[r] - nums[l] > k)
            {
                ++res;
                l = r;
            }
            else
                ++r;
        }

        return res;
    }
};