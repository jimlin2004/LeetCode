struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 單純考操作link-list，感覺下方想法還是有點亂
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if (curr == nullptr) // 空list
            return head;
        ListNode* next = curr->next;

        while (curr && curr->next)
        {
            if (prev)
                prev->next = next;
            else
                head = next;
            ListNode* tempNext = nullptr;
            if (next)
            {
                tempNext = next->next;
                next->next = curr;
            }
            curr->next = tempNext;

            prev = curr;

            if (next->next)
                curr = next->next->next;
            else
                break;
            if (curr)
                next = curr->next;
        }

        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    Solution S;
    S.swapPairs(head);

    return 0;
}