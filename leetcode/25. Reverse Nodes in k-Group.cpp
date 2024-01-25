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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* forward = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (forward != nullptr) {
            int i = 1;
            while (forward != nullptr && i < k) {
                forward = forward->next;
                i++;
            }

            if (forward == nullptr) {
                break;
            }

            bool hasLastNodeDummy = false;
            if (forward->next == nullptr) {
                forward->next = new ListNode();
                hasLastNodeDummy = true;
            }

            if (forward != nullptr) {
                forward = forward->next;
            }

            for (int i = 0; i < k - 1; i++) {
                // interweave
                ListNode* temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
            }

            curr = curr->next;
            for (int i = 0; i < k; i++) {
                prev = prev->next;
            }

            if (hasLastNodeDummy) {
                prev->next = nullptr;
                delete curr;
                forward = nullptr;
            }
        }

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
