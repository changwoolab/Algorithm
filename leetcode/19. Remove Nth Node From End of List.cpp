/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* forward = dummy;
        ListNode* temp = dummy;
        int i = 0;
        while (forward) {
            forward = forward->next;
            if (i > n) temp = temp->next;
            i++;
        }
        ListNode* tempNext = temp->next;
        if (temp->next->next != nullptr) temp->next = temp->next->next;
        else temp->next = nullptr;
        delete tempNext;
        
        return dummy->next;
    }
};
