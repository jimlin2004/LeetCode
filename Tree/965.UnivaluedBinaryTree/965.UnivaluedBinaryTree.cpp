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

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        this->num = root->val;
        return this->DFS(root);
    }
private:
    int num = 0;
    bool DFS(TreeNode* root)
    {
        if (!root)
            return true;
        if (root->val == this->num)
        {
            return this->DFS(root->left) && this->DFS(root->right);
        }
        return false;
    }
};