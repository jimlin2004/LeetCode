#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 只要兩個數字x, y做 x & y 後的答案一定 <= max(x, y)
    // 所以其實這題只要算nums裡最大的數字連續有多少個即可
    int longestSubarray(vector<int>& nums) 
    {
        int n = nums.size();

        int maxAND = *max_element(nums.begin(), nums.end());

        int res = 0;

        int curr = 0;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == maxAND)
            {
                ++curr;

                res = max(res, curr);
            }
            else
            {
                curr = 0;
            }
        }

        return res;
    }
};


int main()
{
    Solution S;
    vector<int> nums = {1,2,3,3,2,2};
    S.longestSubarray(nums);

    return 0;
}