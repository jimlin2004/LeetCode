
// Definition for a binary tree node.
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
    int maxDepth(TreeNode* root) 
    {
        this->DFS(root, 0);
        return this->max_h;
    }
    
private:
    int max_h = 0;
    void DFS(TreeNode* root, int h)
    {
        if (!root)
        {
            if (h > this->max_h)
                this->max_h = h;
                h = 0;
            return;
        }
        h++;
        this->DFS(root->left, h);
        this->DFS(root->right, h);
    }
};