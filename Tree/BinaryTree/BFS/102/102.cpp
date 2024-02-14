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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (!root)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        TreeNode* current;
        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            while (size--)
            {
                current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            res.push_back(level);
        }
        return res;
    }
};