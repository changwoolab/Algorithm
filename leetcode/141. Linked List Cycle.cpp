// https://leetcode.com/problems/linked-list-cycle/solutions/4591486/c-easy-solution-using-hashmap/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> pointerMap;
        ListNode* current = head;
        while (current != NULL) {
            if (pointerMap.count(current)) return true;
            pointerMap[current] = true;
            current = current->next;
        }
        return false;
    }
};
