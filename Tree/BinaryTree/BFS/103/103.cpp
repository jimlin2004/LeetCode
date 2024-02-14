#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        bool isReversed = false;
        while (!q.empty())
        {
            TreeNode* u;
            int n = q.size();
            vector<int> level(n);
            int index;
            for (int i = 0; i < n; ++i)
            {
                u = q.front();
                q.pop();
                index = (isReversed) ? (n - 1 - i) : (i);
                level[index] = u->val;
                if (u->left)
                    q.push(u->left);
                if (u->right)
                    q.push(u->right);
            }
            res.push_back(level);
            isReversed = !isReversed;
        }
        return res;
    }
};