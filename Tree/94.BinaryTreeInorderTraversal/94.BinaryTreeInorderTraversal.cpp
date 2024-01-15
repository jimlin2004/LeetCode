#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
        vector<int> inorderTraversal(TreeNode* root) 
        {
            this->inorder_DFS(root);
            return this->nodes;
        }
    private:
        vector<int> nodes;
        void inorder_DFS(TreeNode* root)
        {
            if (!root)
            {
                return;
            }
            this->inorder_DFS(root->left);
            this->nodes.push_back(root->val);
            this->inorder_DFS(root->right);
        }
};