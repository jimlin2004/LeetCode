struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        this->left_visit(root->left);
        this->right_visit(root->right);
        return this->ans;
    }
    void left_visit(TreeNode* root)
    {
        if (!root)
            return;
        if(!root->left && !root->right)
            this->ans += root->val;
        this->left_visit(root->left);
        this->right_visit(root->right);
        return;
    }
    void right_visit(TreeNode* root)
    {
        if (!root)
            return;
        this->left_visit(root->left);
        this->right_visit(root->right);
        return;
    }
private:
    int ans = 0;
};