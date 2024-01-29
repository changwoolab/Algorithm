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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(-101, head);
        ListNode *slow = dummy, *fast = head;

        int count = 0;
        while (fast != nullptr) {
            if (slow->next->val != fast->val) {
                if (count > 1) slow->next = fast;
                if (slow->next->val != fast->val) slow = slow->next;
                count = 0;
            }
            fast = fast->next;
            count++;
        }

        if (count > 1) slow->next = fast;

        return dummy->next;
    }
};
