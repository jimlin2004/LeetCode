#include <bits/stdc++.h>
#include <unordered_set>
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

class FindElements 
{
private:
    unordered_set<int> containMp;
public:
    // 無聊題目，直接dfs重建樹，然後用hash去記有那些數字即可
    FindElements(TreeNode* root) 
    {
        dfs(root, 0);
    }
    
    bool find(int target) 
    {
        return this->containMp.count(target);
    }

    void dfs(TreeNode* root, int val)
    {
        if (!root)
            return;
        root->val = val;
        this->containMp.insert(val);
        dfs(root->left, (val << 1) + 1);
        dfs(root->right, (val << 1) + 2);
    }
};
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */