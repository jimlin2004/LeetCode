#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    /*
        延續3 sum的作法
        重點是for loop固定枚舉k - 2個數字
        然後剩下的兩個數字利用two pointer搜

        因此複雜度是O(N^3)
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i)
        {
            for (int j = i + 1; j < n - 2; ++j)
            {
                long long currTarget = (long long)target - (long long)nums[i] - (long long)nums[j];

                int l = j + 1;
                int r = n - 1;
                while (l < r)
                {
                    long long currPairSum = (long long)nums[l] + (long long)nums[r];

                    if (currPairSum == currTarget)
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        // 去重複
                        while (l < r && nums[l] == nums[l - 1])
                            ++l;
                        while (l < r && nums[r] == nums[r + 1])
                            --r;
                    }
                    else if (currPairSum < currTarget)
                        ++l;
                    else
                        --r;
                }

                // 去重複
                while (j + 1 < n - 2 && nums[j] == nums[j + 1])
                    ++j;
            }
            while (i + 1 < n - 3 && nums[i] == nums[i + 1])
                ++i;
        }

        return res;
    }
};


int main()
{
    vector<int> vec = {2,2,2,2,2};
    Solution S;
    S.fourSum(vec, 0);

    return 0;
}