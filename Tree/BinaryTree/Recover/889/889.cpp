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
    /*
        建法舉例: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
        一開始樹的root會在preorder的最左邊，postorder的最右邊
        由於假設是full binary tree
        所以第一層選了node 1已滿
        此時知道preorder中1的右邊2是current root的左子樹的root，我們去找postorder中2在哪裡
        找到後可以由postorder知道，在postorder的2左邊的元素(4, 5)都是左子樹的nodes
        遞迴下去可以知道4是左子樹的左子樹，5是左子樹的右子樹
        其他方式也一樣
        過程就是
                        1
                    /       \
                [4,5,2]    [6,7,3]

                        1
                    /         \
                2                3
            /       \         /      \
        4             5     6          7
    */
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int& preorderIndex, int postorderL, int postorderR)
    {
        // 越界條件
        if ((preorderIndex >= preorder.size()) || (postorderR < postorderL))
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderIndex]);
        ++preorderIndex;

        // postorder的window只有一個元素 -> 子樹只有一個node -> 此子樹結束
        if (postorderL == postorderR)
            return root;
        int i;
        // 找到下一個子樹的root有哪些node
        for (i = postorderL; i <= postorderR; ++i)
        {
            if (preorder[preorderIndex] == postorder[i])
                break;
        }
        if (i <= postorderR)
        {
            // 遞迴建樹
            root->left = build(preorder, postorder, preorderIndex, postorderL, i);
            // 注意postorderR要-1，因為current postorder window的最右邊是current的root
            root->right = build(preorder, postorder, preorderIndex, i + 1, postorderR - 1);
        }
        return root;
    }

    // 經典題，雖然preorder跟postorder有不唯一的二元樹
    // 但若假設為full binary tree就有唯一解
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        int preorderIndex = 0;
        return build(preorder, postorder, preorderIndex, 0, postorder.size() - 1);
    }
};