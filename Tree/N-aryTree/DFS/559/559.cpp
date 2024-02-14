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

class Solution 
{
public:
    int maxDepth(Node* root) 
    {
        this->DFS(root, 0);
        return this->max_h;
    }
private:
    int max_h = 0;
    void DFS(Node* root, int h)
    {
        if (!root)
        {
            if (h > this->max_h)
                this->max_h = h;
            return;
        }
        h++;
        for (Node* child: root->children)
        {
            this->DFS(child, h);
        }
        if (h > this->max_h)
            this->max_h = h;
        return;
    }
};