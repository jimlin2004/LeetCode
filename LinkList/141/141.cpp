#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        if (!head)
            return false;
        auto it = this->table.find(head);
        if (it == this->table.end())
            this->table[head] = true;
        else
            return true;
        return false || this->hasCycle(head->next);
    }
private:
    unordered_map<ListNode*, bool> table;
};