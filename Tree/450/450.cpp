#include <bits/stdc++.h>
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
    TreeNode* find_smallest(TreeNode* root)
    {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root)
            return nullptr;
        if (key < root->val)
            root->left = this->deleteNode(root->left, key);
        else if (key > root->val)
            root->right = this->deleteNode(root->right, key);
        else
        {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else
            {
                TreeNode* smallest_node = this->find_smallest(root->right);
                root->val = smallest_node->val;
                root->right = this->deleteNode(root->right, smallest_node->val);
            }
        }
        return root;
    }
};