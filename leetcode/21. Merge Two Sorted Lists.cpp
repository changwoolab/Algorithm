// https://leetcode.com/problems/merge-two-sorted-lists/solutions/4598534/c-solution-with-iterative-approach/

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
private:
    int NULL_VALUE = 101;

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ansNode = new ListNode();

        ListNode* temp = ansNode;
        while (list1 != nullptr || list2 != nullptr) {
            int num1 = list1 != nullptr ? list1->val : NULL_VALUE;
            int num2 = list2 != nullptr ? list2->val : NULL_VALUE;

            if (num1 > num2) {
                ListNode* newNode = new ListNode(num2);
                list2 = list2->next;
                temp->next = newNode;
                temp = temp->next;
            } else {
                ListNode* newNode = new ListNode(num1);
                list1 = list1->next;
                temp->next = newNode;
                temp = temp->next;
            }
        }

        ListNode* ans = ansNode->next;
        delete ansNode;
        return ans;
    }
};
