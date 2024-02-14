#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> res;
        if (!root)
            return res;
        q.push(root);
        Node* current;
        while (!q.empty())
        {
            int len = q.size();
            vector<int> level;
            while (len--)
            {
                current = q.front();
                q.pop();
                level.push_back(current->val);
                for (Node* node: current->children)
                    q.push(node);
            }
            res.push_back(level);
        }
        return res;
    }
};