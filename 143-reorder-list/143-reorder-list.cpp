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
    void reorderList(ListNode* head) {
        //first, find the size of linked list
        ListNode *slow = head, *fast = head, *curr = head, *prev = NULL;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //now slow points to the middle of the LL
        stack<ListNode*> st;
        while(slow) {
            st.push(slow);
            slow = slow->next;
        }
        while(!st.empty()) {
            ListNode *top = st.top();
            st.pop();
            if(curr == top) {
                break;
            }
            prev = curr->next;
            curr->next = top;
            top->next = prev;
            curr = prev;
        }
        curr->next = NULL;


    }
};