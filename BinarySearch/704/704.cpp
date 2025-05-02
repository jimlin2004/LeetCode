#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int L = -1, R = nums.size();
        while (L + 1 < R)
        {
            int mid = (L + R) >> 1;
            if (nums[mid] <= target)
                L = mid;
            else
                R = mid;
        }

        return (L >= 0 && nums[L] == target) ? L : -1;
    }
};