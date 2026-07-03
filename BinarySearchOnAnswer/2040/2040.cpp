#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:

    long long check(vector<int>& nums1, vector<int>& nums2, long long x)
    {
        long long total = 0;
        for (int n1: nums1)
        {
            if (n1 < 0)
            {
                // nums1[i] * nums2[j] <= x
                // 因為nums1[i] < 0
                // 所以nums2[j] >= x / nums1[i]
                long long target = ceil((double)x / n1);
                int indexOfNums2 = lower_bound(nums2.begin(), nums2.end(), target) - nums2.begin();
                total += nums2.size() - indexOfNums2;
            }
            else if (n1 > 0)
            {
                // nums1[i] * nums2[j] <= x
                // 因為nums1[i] > 0
                // 所以nums2[j] <= x / nums1[i]
                long long target = floor((double)x / n1);
                // 用upper_bound找到第一個 > x的位置
                int indexOfNums2 = upper_bound(nums2.begin(), nums2.end(), target) - nums2.begin();
                total += indexOfNums2;
            }
            else // n1 == 0
            {
                // 因為n1 == 0
                // 所以全部nums2[j] * n1 -> 0
                if (x >= 0)
                    total += nums2.size();
            }
        }

        return total;
    }

    // 二分搜答案 + 算有幾個乘積 <= mid

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        long long l = -2e10;
        long long r = 2e10;
        while (l + 1 < r)
        {
            long long mid = (l + r) / 2;
            if (check(nums1, nums2, mid) >= k) // 定義>=k是合法，l是不合法
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        return r;
    }
};

int main()
{
    vector<int> nums1 = {-4,-2,0,3};
    vector<int> nums2 = {2,4};
    Solution S;
    S.kthSmallestProduct(nums1, nums2, 2);
}