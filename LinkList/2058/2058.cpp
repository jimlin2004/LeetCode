#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    // 最大距離一定是第一個critical node跟最後一個
    // 其他就是link list水題
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        int firstCritical = -1;
        int lastCritical = -1;
        int prevCritical = -1;
        int minDist = 0x3f3f3f3f;

        ListNode* prev = head;
        ListNode* curr = head->next;
        if (curr->next == nullptr)
            return {-1, -1};
        ListNode* next = curr->next;

        int currIndex = 1;
        while (next != nullptr)
        {
            if ((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val))
            {
                if (firstCritical == -1)
                    firstCritical = currIndex;
                lastCritical = currIndex;
                if (prevCritical != -1)
                    minDist = min(minDist, currIndex - prevCritical);
                prevCritical = currIndex;
            }

            prev = curr;
            curr = next;
            ++currIndex;
            next = next->next;
        }

        if (firstCritical == -1)
            return {-1, -1};
        if (firstCritical == lastCritical)
            return {-1, -1};
        return {minDist, lastCritical - firstCritical};
    }
};