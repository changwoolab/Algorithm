// https://leetcode.com/problems/add-two-numbers/solutions/4595963/c-solution/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();

        ListNode* traverser = ans;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int n1 = l1 == nullptr ? 0 : l1->val;
            int n2 = l2 == nullptr ? 0 : l2->val;

            int res = n1 + n2 + carry;
            carry = res / 10;
            traverser->val = res % 10;

            if (carry != 0 
                    || (l1 != nullptr && l1->next != nullptr) 
                    || (l2 != nullptr && l2->next != nullptr)) {
                ListNode* node = new ListNode();
                traverser->next = node;
                traverser = traverser->next;
            }
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return ans;
    }
};
