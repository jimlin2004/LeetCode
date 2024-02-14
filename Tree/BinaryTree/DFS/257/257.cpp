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
    vector<string> binaryTreePaths(TreeNode* root) 
    {   
        vector<int> tmp;
        this->DFS(root, tmp);
        return this->ret;
    }
private:
    vector<string> ret;
    void DFS(TreeNode* root, vector<int> tmp)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            tmp.push_back(root->val);
            this->vec2string(tmp);
            return;
        }
        tmp.push_back(root->val);
        this->DFS(root->left, tmp);
        this->DFS(root->right, tmp);
    }
    void vec2string(vector<int> vec)
    {
        if (vec.empty())
            return;
        int N = vec.size();
        string str = "";
        for (int i = 0; i < N; i++)
        {
            str += to_string(vec[i]);
            if (i != N - 1)
                str += "->";
        }
        this->ret.push_back(str);
    }
};