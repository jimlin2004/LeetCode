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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        this->DFS(p, this->p_vec);
        this->DFS(q, this->q_vec);
        return true ? (this->p_vec == this->q_vec) : false;
    }
private:
    vector<int> p_vec, q_vec;
    void DFS(TreeNode* root,vector<int> &vec)
    {
        if (!root)
        {
            vec.push_back(-1);
            return;
        }
        vec.push_back(root->val);
        this->DFS(root->left, vec);
        this->DFS(root->right, vec);
    }
};