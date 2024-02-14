#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        this->DFS_preorder(root);
        return this->result;
    }
private:
    vector<int> result;
    void DFS_preorder(Node* root)
    {
        if (!root)
            return;
        this->result.push_back(root->val);
        for (Node* child: root->children)
        {
            this->DFS_preorder(child);
        }
        return;
    }
};