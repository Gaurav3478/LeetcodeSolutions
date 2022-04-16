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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        unordered_set<ListNode *> ust;
        while(head1!=NULL) {
            ust.insert(head1);
            head1 = head1->next;
        }
        while(head2!=NULL) {
            if(ust.find(head2)!=ust.end()) {
                return head2;
            }
            head2 = head2->next;
        }
        return NULL;
    }
};