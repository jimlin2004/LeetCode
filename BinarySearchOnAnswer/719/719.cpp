#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        因為sort後整個數列
        但是差距並沒有單調性
        比如
        nums = [1, 10, 11, 20]
        (1, 10) -> 9
        (10, 11) -> 1
        (11, 20) -> 9

        所以改用對答案二分搜

        此時變成需要做到快速知道有多少個pair 差距 <= mid
        做法是利用滑動窗戶O(N)找
    */

    int check(vector<int>& nums, int mid)
    {
        int n = nums.size();

        int res = 0;
        int l = 0, r = 1;
        while (r < n)
        {
            while (l < r && nums[r] - nums[l] > mid)
                ++l;
            res += (r - l); // 此時(l, r), (l + 1, r), ...都可以
            ++r; // 換下一個右邊界
        }

        return res;
    }

    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        int l = -1, r = (nums.back() - nums.front()) + 1;

        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            if (check(nums, mid) >= k)
                r = mid;
            else
                l = mid;
        }

        return r;
    }
};