#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        this->dfs(0, {}, nums, res);
        return res;
    }
private:
    void dfs(int index, vector<int> subset, vector<int>& nums, vector<vector<int>>& res)
    {
        if (index == nums.size())
        {
            res.push_back(subset);
            return;
        }
        this->dfs(index + 1, subset, nums, res);
        subset.emplace_back(nums[index]);
        this->dfs(index + 1, subset, nums, res);
    }
};