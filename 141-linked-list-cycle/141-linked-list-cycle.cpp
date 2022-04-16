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
        unordered_set<ListNode *> ust;
        while(head!=NULL) {
            if(ust.find(head)!=ust.end()) {
                return true;
            }
            ust.insert(head);
            head = head->next;
        }
        return false;
    }
};