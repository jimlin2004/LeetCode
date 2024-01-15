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
    int getMinimumDifference(TreeNode* root) 
    {
        //O(n)
        this->dfs(root);
        std::vector<int>::iterator pre = this->vec.begin();
        for (int i = 1; i < this->vec.size(); i++)
        {
            this->pq.push(-(this->vec[i] - *pre));
            pre++;
        }
        return -(this->pq.top());
    }
    void dfs(TreeNode* root)
    {
        //inorder->sorted vector
        if (!root)
            return;
        this->dfs(root->left);
        this->vec.push_back(root->val);
        this->dfs(root->right);
        return;
    }
private:
    priority_queue<int> pq;
    vector<int> vec;
};