
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
    int countNodes(TreeNode* root) 
    {
        this->dfs(root);
        return this->res;
    }
private:
    int res = 0;
    void dfs(TreeNode* root)
    {
        if (!root)
            return;
        ++this->res;
        this->dfs(root->left);
        this->dfs(root->right);
    }
};