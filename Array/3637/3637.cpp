#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // O(n)檢查一下arr是不是符合提議要求即可
    bool isTrionic(vector<int>& nums)
    {
        int n = nums.size();

        int l = 0;
        for (; l + 1 < n; ++l)
        {
            if (nums[l] >= nums[l + 1])
                break;
        }

        if (l == 0 || l >= n - 1)
            return false;
        
        int mid = l;
        for (; mid + 1 < n; ++mid)
        {
            if (nums[mid] <= nums[mid + 1])
                break;
        }

        if (mid == l || mid >= n - 1)
            return false;

        int r = mid;
        for (; r + 1 < n; ++r)
        {
            if (nums[r] >= nums[r + 1])
                break;
        }

        if (r < n - 1 || l >= r || r == mid)
            return false;

        return true;
    }
};


int main()
{
    Solution S;
    vector<int> nums = {3,7,1};
    S.isTrionic(nums);
}