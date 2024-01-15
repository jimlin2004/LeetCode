#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    bool isBalanced(TreeNode* root) 
    {
        if (!root)
            return true;
        int left = this->DFS(root->left);
        int right = this->DFS(root->right);
        return (abs(left - right) <= 1) && this->isBalanced(root->left) && this->isBalanced(root->right);
    }
private:
    int DFS(TreeNode* root)
    {
        if (!root)
            return 0;
        return max(this->DFS(root->left), this->DFS(root->right)) + 1;
    }
};