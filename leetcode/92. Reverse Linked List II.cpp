// https://leetcode.com/problems/reverse-linked-list-ii/solutions/4613049/c-simple-solution-using-stack-beats-100/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> values;

        ListNode* temp = head;
        int i = 1;
        while (temp) {
            if (i >= left && i <= right) values.push(temp->val);
            temp = temp->next;
            i++;
        }

        temp = head;
        i = 1;
        while (temp) {
            if (i >= left && i <= right) {
                int val = values.top();
                values.pop();
                temp->val = val;
            }
            temp = temp->next;
            i++;
        }
        
        return head;
    }
};
