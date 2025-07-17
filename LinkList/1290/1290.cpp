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
    int getDecimalValue(ListNode* head) 
    {
        int res = 0;
        ListNode* curr = head;
        while (curr)
        {
            res = (res << 1) | (curr->val);
            curr = curr->next;
        }

        return res;
    }
};