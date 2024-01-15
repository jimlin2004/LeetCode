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
    int minDepth(TreeNode* root) 
    {
        return this->DFS(root);
    }
private:
    int DFS(TreeNode* root)
    {
        if (!root)
            return 0;
        else if (root->left && root->right)
            return min(this->DFS(root->left), this->DFS(root->right)) + 1;
        return max(this->DFS(root->left), this->DFS(root->right)) + 1;
    } 
};