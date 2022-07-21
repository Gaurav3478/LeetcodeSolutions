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
        set<ListNode*> s;
        // map<ListNode*, int> mp;
        ListNode *temp = head;
        bool cycle = false;
        while(temp->next != NULL) {
            if(s.find(temp) != s.end()) {
                cycle = true;
                break;
            }
            // mp[temp]++;
            s.insert(temp);
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