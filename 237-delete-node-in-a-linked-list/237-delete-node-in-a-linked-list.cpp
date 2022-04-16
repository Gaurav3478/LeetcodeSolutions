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
    void deleteNode(ListNode* node) {
        ListNode *prevNode;
        while(node->next!=NULL) {
            node->val = node->next->val;
            prevNode = node;
            node = node->next;
        }
        prevNode->next = NULL;
    }
};