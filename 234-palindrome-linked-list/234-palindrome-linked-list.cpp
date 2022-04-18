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
    
    ListNode* reverseLL(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt = NULL;
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *fastPtr = head, *slowPtr = head;
        while(fastPtr->next && fastPtr->next->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        //now slowPtr contains the middle element
        //I now want to reverse the linked list from the middle (inclusive) to the end
        slowPtr->next = reverseLL(slowPtr->next);
        // cout << slowPtr->val << endl; 

        ListNode *newPtr = head;
        slowPtr = slowPtr->next;
        while(slowPtr) {
            if(newPtr->val != slowPtr->val) {
                return false;
            }
            newPtr = newPtr->next;
            slowPtr = slowPtr->next;
        }
        return true;
    }
};