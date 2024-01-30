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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = getLength(head);
        if (length <= 1) return head;

        k = length - (k % length);

        ListNode* nextHead = head;
        ListNode* lastOfList = nextHead;
        for (int i = 0; i < k - 1; i++) nextHead = nextHead->next;
        while(lastOfList->next != nullptr) lastOfList = lastOfList->next;

        lastOfList->next = head;
        head = nextHead->next;
        nextHead->next = nullptr;

        return head;
    }
private:
    int getLength(ListNode* list) {
        int length = 0;
        while (list != nullptr) {
            list = list->next;
            length++;
        }
        return length;
    }
};
