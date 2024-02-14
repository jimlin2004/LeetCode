#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
        this->res = -9999;
        this->dfs(root);
        return this->res;
    }

    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;
        //如果比0小就不選，故l、r < 0 => 0
        int l = max(this->dfs(root->left), 0);
        int r = max(this->dfs(root->right), 0);
        this->res = max(this->res, l + r + root->val);
        return max(l, r) + root->val;
    }
private:
    int res;
};