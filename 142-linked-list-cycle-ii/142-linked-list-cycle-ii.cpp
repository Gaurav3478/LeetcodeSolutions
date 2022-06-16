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
    ListNode *detectCycle(ListNode *head) {
        //Floyd's algorithm
        if(head == NULL) {
            return NULL; 
        }
        ListNode *slow = head, *fast = head;
        while(slow != NULL && fast != NULL) {
            slow = slow->next;
            if(fast->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        if(slow != fast) {
            return NULL;
        }
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};