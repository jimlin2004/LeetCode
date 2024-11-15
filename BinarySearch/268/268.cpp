#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        //先對數字排序小到大
        sort(nums.begin(), nums.end());

        //[l, r]裡二分
        int l = 0, r = nums.size();

        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] > mid) //如果nums[mid] > mid代表missing的數字在左半邊
                r = mid;
            else
                l = mid + 1; //如果nums[mid] == mid代表missing的數字在右半邊
        }
        return l;
    }
};