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
    int sumEvenGrandparent(TreeNode* root) 
    {
        this->dfs(root);
        return this->res;
    }
private:
    int res = 0;
    void addIfVaild(TreeNode* root)
    {
        if (root)
            res += root->val;
    }
    void dfs(TreeNode* root)
    {
        if (!root)
            return;
        if (root->val % 2 == 0)
        {
            if (root->left)
            {
                this->addIfVaild(root->left->left);
                this->addIfVaild(root->left->right);
            }
            if (root->right)
            {
                this->addIfVaild(root->right->left);
                this->addIfVaild(root->right->right);
            }
        }
        this->dfs(root->left);
        this->dfs(root->right);
    }
};