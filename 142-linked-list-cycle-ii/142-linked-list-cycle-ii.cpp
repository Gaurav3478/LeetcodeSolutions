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
        map<ListNode *, int> mp;
        ListNode *temp = head;
        while(temp) {
            if(mp[temp] > 0) {
                return temp;
            }
            mp[temp]++;
            temp = temp->next;
        }
        return NULL;
    }
};