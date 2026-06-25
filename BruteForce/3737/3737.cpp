#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int res = 0;
        int n = nums.size();
        // 枚舉所有subarray，O(n^2)
        for (int i = 0; i < n; ++i)
        {
            int targetCnt = 0;
            for (int j = i; j < n; ++j)
            {
                if (nums[j] == target)
                    ++targetCnt;
                if (targetCnt * 2 > (j - i + 1))
                    ++res;
            }
        }

        return res;
    }
};