#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 水題，sort後3個3個分組結束
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        int n = nums.size();
        for (int i = 0; i < n; i += 3)
        {
            vector<int> vec({nums[i]});
            for (int j = 1; j < 3; ++j)
            {
                if (nums[i + j] - vec[0] <= k)
                    vec.push_back(nums[i + j]);
                else
                    return {};
            }

            res.push_back(vec);
        }

        return res;
    }
};