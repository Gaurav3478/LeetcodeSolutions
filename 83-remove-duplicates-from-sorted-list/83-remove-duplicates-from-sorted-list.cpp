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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        map<int, int> mp;
        ListNode *temp = head;
        mp[head->val]++;
        while(temp->next) {
            if(mp[temp->next->val]) {
                temp->next = temp->next->next;
            }
            else {
                mp[temp->next->val]++;
                temp = temp->next;
            }
        }
        return head;
    }
};