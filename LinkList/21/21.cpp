#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        return this->rec(l1, l2);
    }
private:
    ListNode* rec(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        else if (!l2)
        {
            return l1;
        }
        
        ListNode* link;
        if (l1->val >= l2->val)
        {
            link = l2;
            link->next =  this->rec(l1, l2->next);
        }
        else
        {
            link = l1;
            link->next = this->rec(l1->next, l2);
        }
        return link;
    }
};