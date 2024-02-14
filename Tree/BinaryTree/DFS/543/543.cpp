#include <algorithm>
using namespace std;

struct TreeNode {
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
    int diameterOfBinaryTree(TreeNode* root)
    {
        this->ans = 0;
        this->dfs(root);
        return this->ans;
    }
    int dfs(TreeNode* root)
    {
        if (!root)
            return -1;
        int left = this->dfs(root->left) + 1;
        int right = this->dfs(root->right) + 1;
        this->ans = max(this->ans, left + right);
        return max(left, right);
    }
private:
    int ans;
};