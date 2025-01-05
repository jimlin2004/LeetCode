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
    //只好乖乖地dfs，每拜訪一個+1，直到第k個
    //O(n)
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans = 0;
        dfs(root, 0, k, ans);
        return ans;
    }

    int dfs(TreeNode* root, int cnt, int target, int& ans)
    {
        if (!root)
            return cnt;
        if (cnt > target)
            return cnt;
        cnt = dfs(root->left, cnt, target, ans);
        // 拜訪自己
        ++cnt;
        if (cnt == target)
        {
            ans = root->val;
            return cnt;
        }
        cnt = dfs(root->right, cnt, target, ans);
        return cnt;
    }
};