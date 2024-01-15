#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list.*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty())
        {
            ListNode* node = new ListNode();
            node->val = NULL;
            node->next = NULL;
            return node->next;
        }
        for (auto node: lists)
            this->read(node);
        if (this->nums.empty())
        {
            ListNode* node = new ListNode();
            node->val = NULL;
            node->next = NULL;
            return node->next;
        }
        sort(this->nums.begin(), this->nums.end());
        return this->build();
    }
private:
    vector<int> nums;
    void read(ListNode* root)
    {
        if (!root)
            return;
        this->nums.push_back(root->val);
        this->read(root->next);
    }
    ListNode* build()
    {
        ListNode* head = new ListNode();
        head->val = this->nums[0];
        head->next = NULL;
        ListNode* node = head;
        int ln = this->nums.size();
        for (int i = 1; i < ln; i++)
        {
            node->next = new ListNode();
            node = node->next;
            node->val = this->nums[i];
            node->next = NULL;
        }
        node = head;
        return node;
    }
};