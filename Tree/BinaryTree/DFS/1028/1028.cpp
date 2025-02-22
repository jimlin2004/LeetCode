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

struct Token
{
    int depth;
    int val;
};

class Solution 
{
public:
    vector<Token> parseTraversal(const string& traversal)
    {
        vector<Token> tokens;

        int n = traversal.size();

        int i = 0;
        int depth = 0;
        int val = 0;
        
        while (i < n)
        {
            depth = 0;
            val = 0;
            while (i < n && traversal[i] == '-')
            {
                ++depth;
                ++i;
            }
            
            while(i < n && traversal[i] != '-')
            {
                val = val * 10 + (traversal[i] - '0');
                ++i;
            }

            tokens.push_back({depth, val});
        }
        return tokens;
    }

    TreeNode* buildTree(int& index, const vector<Token>& tokens)
    {
        int currDepth = tokens[index].depth;
        TreeNode* root = new TreeNode(tokens[index].val);
        // 看有沒有children
        if ((index + 1 < tokens.size()) && (tokens[index + 1].depth == currDepth + 1))
        {
            ++index;
            root->left = buildTree(index, tokens);
        }
        if ((index + 1 < tokens.size()) && (tokens[index + 1].depth == currDepth + 1))
        {
            ++index;
            root->right = buildTree(index, tokens);
        }
        return root;
    }

    // 先處理輸入的traversal的tokenize，然後用dfs重建樹
    TreeNode* recoverFromPreorder(string traversal) 
    {
        vector<Token> tokens = parseTraversal(traversal);
        int index = 0;
        return buildTree(index, tokens);
    }
};


int main()
{
    string traversal = "1-2--3--4-5--6--7";
    Solution S;
    TreeNode* root = S.recoverFromPreorder(traversal);
    return 0;
}