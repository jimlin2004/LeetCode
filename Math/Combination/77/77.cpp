#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        makeCombine(res, {}, 1, n, k);
        return res;
    }

    void makeCombine(vector<vector<int>> &res, vector<int> subset, int num, int n, int k)
    {
        if (subset.size() == k)
        {
            res.push_back(subset);
            return;
        }
        for (int i = num; i <= n; i++)
        {
            subset.push_back(i);
            makeCombine(res, subset, i + 1, n, k);
            subset.pop_back(); //pop掉上一i
        }
    } 
};

int main()
{
    Solution s;
    s.combine(4, 2);
}