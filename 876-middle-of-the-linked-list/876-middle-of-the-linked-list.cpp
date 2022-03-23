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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int count = 0;
        while(temp->next!=NULL) {
            count++;
            temp = temp->next;
        }
        ListNode *temp2 = head;
        for(int i=0; i<(count+1)/2; i++) {
            temp2 = temp2->next;
        }
        return temp2;
    }
};