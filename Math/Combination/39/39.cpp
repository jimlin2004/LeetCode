#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        if (target == 0)
            return res;
        sort(candidates.begin(), candidates.end());
        this->dfs(candidates, res, 0, target, {});
        return res;
    }
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, int index, int remain, vector<int> combination)
    {
        if (remain == 0)
            res.push_back(combination);
        if (index >= candidates.size())
            return;
        if (remain >= candidates[index])
            this->dfs(candidates, res, index + 1, remain, combination);
        while (remain >= candidates[index])
        {
            combination.emplace_back(candidates[index]);
            remain -= candidates[index];
            this->dfs(candidates, res, index + 1, remain, combination);
        }
    }
};

int main()
{
    vector<int> cand = {2, 3, 6, 7};
    Solution s;
    s.combinationSum(cand, 7);
    return 0;
}