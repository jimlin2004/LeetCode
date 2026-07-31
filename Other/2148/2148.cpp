#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 水題
    int countElements(vector<int>& nums)
    {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        int res = 0;
        for (int num: nums)
        {
            if (minNum < num && num < maxNum)
                ++res;
        }

        return res;
    }
};