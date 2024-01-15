#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *l, *r;
    Node() { this->val = 0; }
    Node(int val) { this->val = val; }
    Node(Node* l, Node* r)
    {
        this->l = l;
        this->r = r;
        this->pull();
    }
    void pull()
    {
        this->val = this->l->val + this->r->val;
    }
};

class NumArray 
{
public:
    NumArray(vector<int>& nums) 
    {
        this->N = nums.size();
        N--;
        this->root = this->build(0, N, nums);
    }
    
    void update(int index, int val) 
    {
        this->modify(this->root, 0, N, index, val);
    }
    
    int sumRange(int left, int right) 
    {
        return this->query(this->root, 0, N, left, right);
    }

private:
    Node* root;
    int N;

    Node* build(int l, int r, vector<int>& nums)
    {
        if (l == r)
            return new Node(nums[l]);
        int mid = (l + r) >> 1;
        return new Node(build(l, mid, nums), build(mid + 1, r, nums));
    }

    void modify(Node* node, int l, int r, int pos, int k)
    {
        if (l == r)
        {
            node->val = k;
            return ;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            this->modify(node->l, l, mid, pos, k);
        else
            this->modify(node->r, mid + 1, r, pos, k);
        node->pull();
    }

    int query(Node* node, int l, int r, int ql, int qr)
    {
        if (r < ql || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return node->val;
        int mid = (l + r) >> 1;
        return this->query(node->l, l, mid, ql, qr) + this->query(node->r, mid + 1, r, ql, qr);
    }
};

int main()
{
    vector<int> nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    printf("%d\n", obj->sumRange(0, 2));
    obj->update(1, 2);
    printf("%d\n", obj->sumRange(0, 2));
}