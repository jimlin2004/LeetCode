#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 照著題目要求做而已
    long long gcdSum(vector<int>& nums)
    {
        vector<int> leftMax(nums.size(), 0);
        vector<int> prefixGcd(nums.size(), 0);
        leftMax[0] = nums[0];
        prefixGcd[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
            prefixGcd[i] = gcd(nums[i], leftMax[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        long long res = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            res += gcd(prefixGcd[l], prefixGcd[r]);
            ++l;
            --r;
        }

        return res;
    }
};