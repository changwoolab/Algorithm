// https://leetcode.com/problems/copy-list-with-random-pointer/solutions/4608945/c-solution-using-hash-map/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToNew;
        Node* newNodeHead = new Node(0);

        Node* temp = head;
        Node* newNodeTemp = newNodeHead;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNodeTemp->next = newNode;
            newNodeTemp = newNodeTemp->next;
            oldToNew[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        newNodeTemp = newNodeHead->next;
        while (temp) {
            newNodeTemp->random = oldToNew[temp->random];

            newNodeTemp = newNodeTemp->next;
            temp = temp->next;
        }

        Node* ans = newNodeHead->next;
        delete newNodeHead;
        return ans;
    }
};
