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
        ListNode *temp = head;
        int count = 1;
        while(temp!=nullptr && temp->next != nullptr) {
            count++; 
            temp = temp->next;
        } 
        if(count == 1) {
            head = nullptr;
            return head;
        }
        // cout << "count = " << count << endl;
        int stopping_index = count-n+1;
        int new_index = 1;
        // cout << stopping_index;
        temp = head;
        if(stopping_index == new_index) {
            return temp->next;
        }
        while(temp->next!=nullptr) {
            if(stopping_index-1 == new_index) {
                temp->next = temp->next->next;
                return head;
            }
            new_index++;
            temp = temp->next;
        }
        return head;
    }
};