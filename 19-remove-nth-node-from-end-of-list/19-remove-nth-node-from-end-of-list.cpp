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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //count the number of nodes
        //we have to remove the n'th node from the end. therefore we have to remove the (count - n'th) node from the start
        //upon reaching that node, do the change
        ListNode *temp = head;
        if(head == NULL) {
            return head;
        }
        int count = 1;
        while(temp->next) {
            temp = temp->next;
            count++;
        }
        int k = count - n;
        temp = head;
        if(k == 0) {
            return temp->next;
        }
        else {
            k--;
        }
        while(k--) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
    
};