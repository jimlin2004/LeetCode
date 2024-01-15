#include <vector>
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
    bool isValidBST(TreeNode* root) 
    {
        this->inoder(root);
        if (this->nodes.size() <= 1)
            return true;
        for (int i = 1; i < this->nodes.size(); ++i)
        {
            if (this->nodes[i] <= this->nodes[i - 1])
                return false;
        }
        return true;
    }
    void inoder(TreeNode* root)
    {
        if (!root)
            return;
        this->inoder(root->left);
        this->nodes.push_back(root->val);
        this->inoder(root->right);
    }
private:
    vector<int> nodes;
};