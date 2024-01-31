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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode();
        ListNode* second = new ListNode();

        ListNode* firstTemp = first;
        ListNode* secondTemp = second;
        ListNode* temp;
        while (head) {
            temp = head;

            if (temp->val >= x) {
                secondTemp->next = temp;
                secondTemp = secondTemp->next;
            } else {
                firstTemp->next = temp;
                firstTemp = firstTemp->next;
            }

            head = head->next;
            temp->next = nullptr;
        }

        if (!(first->next)) return second->next;
        ListNode* ans = first->next;
        firstTemp->next = second->next;
        return ans;
    }
};
