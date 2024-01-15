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
    bool isSymmetric(TreeNode* root) 
    {
        if (!root)
            return true;
        return this->check(root->left, root->right);
    }
private:
    bool check(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
            return true;
        else if (!p || !q)
            return false;
        else if (p->val != q->val)
            return false;
        return this->check(p->left, q->right) && this->check(p->right, q->left);
    }
};