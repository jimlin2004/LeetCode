#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<int, int> dict;
        unordered_map<int, int> dict;
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            if (dict.find(target - nums[i]) == dict.end())
                dict[nums[i]] = i;
            else
            {
                vec.push_back(dict[target - nums[i]]);
                vec.push_back(i);
                break;
            }
        }
        return vec;
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int t = 9;
    Solution s;
    s.twoSum(nums, t);
    return 0;
}