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
    bool hasCycle(ListNode *head) {
        if(head == NULL) {
            return false;
        } 
        map<ListNode*, int> mp;
        ListNode *temp = head;
        bool cycle = false;
        while(temp->next != NULL) {
            if(mp[temp]) {
                cycle = true;
                break;
            }
            mp[temp]++;
            temp = temp->next;
        }
        if(!cycle) {
            return false;
        }
        else {
            return true;
        }
    }
};