#include <bits/stdc++.h>
using namespace std;

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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        this->postorder(root);
        return this->result;
    }
private:
    vector<int> result;
    void postorder(TreeNode* root)
    {
        if (!root)
            return;
        this->postorder(root->left);
        this->postorder(root->right);
        this->result.push_back(root->val);
    }
};