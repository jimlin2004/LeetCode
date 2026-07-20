#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int i, vector<int>& nums)
    {
        if (nums[i] == nums[i - 1] && (i % 2 == 1))
            return true;
        if (nums[i] == nums[i + 1] && (i % 2 == 0))
            return true;
        return false;
    }

    // 利用index與相等關係判斷，利用二分搜
    int singleNonDuplicate(vector<int>& nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int l = 0, r = n;
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, nums))
                l = mid;
            else
                r = mid;
        }

        return nums[r];
    }
};