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
    pair<int, int> dfs(TreeNode* u, int& res)
    {
        if (u == nullptr)
            return make_pair(0, 0);
        pair<int, int> leftSubtree = dfs(u->left, res);
        pair<int, int> rightSubtree = dfs(u->right, res);

        pair<int, int> currSubtree = make_pair(leftSubtree.first + rightSubtree.first + 1, leftSubtree.second + rightSubtree.second + u->val);
        if (currSubtree.second / currSubtree.first == u->val)
            ++res;
        return currSubtree;
    }

    // dfs水題
    int averageOfSubtree(TreeNode* root) 
    {
        int res = 0;
        dfs(root, res);
        return res;
    }
};