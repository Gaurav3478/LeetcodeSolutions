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
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }
        
        if (q.empty()) {
            return NULL;
        }
        if(q.size() == 1) {
            return q.top();
        }
        ListNode *result = q.top();
        ListNode *temp = result;
        q.pop();
        if(result->next) {
            q.push(result->next);
        }
        while(!q.empty()) {
            temp->next = q.top();
            q.pop();
            temp = temp->next;
            if(temp->next) {
                q.push(temp->next);
            }
        }
        return result;
    }
};