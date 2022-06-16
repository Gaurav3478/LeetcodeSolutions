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
    ListNode* mergelist(ListNode *ptr1, ListNode* ptr2) {
        ListNode *init = new ListNode();
        ListNode *ans = init;
        while(ptr1 != NULL && ptr2 != NULL) {
            if(ptr1->val < ptr2->val) {
                ListNode *temp = new ListNode(ptr1->val);
                ans->next = temp;
                ptr1 = ptr1->next;
            }
            else {
                ListNode *temp = new ListNode(ptr2->val);
                ans->next = temp;
                ptr2 = ptr2->next;
            }
            ans = ans->next;
        }
        while(ptr1 != NULL) {
            ListNode *temp = new ListNode(ptr1->val);
            ans->next = temp;
            ptr1 = ptr1->next;
            ans = ans->next;
        }
        while(ptr2 != NULL) {
            ListNode *temp = new ListNode(ptr2->val);
            ans->next = temp;
            ptr2 = ptr2->next;
            ans = ans->next;
        }
        return init->next;
    }

    ListNode* sortList(ListNode* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
            
    }
};