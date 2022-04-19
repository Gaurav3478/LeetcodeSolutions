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
        ListNode *temp = head;
        int length = 0;
        
        if(head == NULL || head->next == NULL) {
            return head;
        }
        while(temp) {
            length++;
            temp = temp->next;
        }       
        k %= length;
        //now I have the length of the linked list
        temp = head;
        while(true) {
            if(temp->next == NULL) {
                temp->next = head;
                break;
            }
            temp= temp->next;
        }
        temp = head;
        int cnt = 0;
        while(temp) {
            if(cnt == length-k-1) {
                ListNode *returnVal = temp->next;
                temp->next = NULL;
                return returnVal;
            }
            cnt++;
            temp = temp->next;
        }
        return head;
    }
};