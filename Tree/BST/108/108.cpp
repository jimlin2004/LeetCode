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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return this->add(nums, 0, nums.size());
    }
private:
    TreeNode* add(vector<int>& nums, int begin, int end)
    {
        if (begin >= end)
            return NULL;
        int mid = (begin + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = this->add(nums, begin, mid);
        node->right = this->add(nums, mid + 1, end);
        return node;
    }
};