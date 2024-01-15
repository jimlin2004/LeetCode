#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        this->get_lenght(head);
        ListNode* current = head;
        ListNode* previous;
        int i = 0;
        while (current != nullptr && i != (this->size - n))
        {
            i++;
            previous = current;
            current = current->next;
        }
        if (current == head)
        {
            head = current->next;
            delete current;
            current = nullptr;
        }
        else
        {
            previous->next = current->next;
            delete current;
            current = nullptr;
        }
        return head;
    }
private:
    int size = 0;
    void get_lenght(ListNode* head)
    {
        ListNode* current = head;
        while(current != nullptr)
        {
            current = current->next;
            this->size++;
        }
    }
};