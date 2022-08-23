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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            return false;
        }
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL) {
            if(fast->next->next == NULL) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        ListNode *temp = head;
        string s1 = "", s2 = "";
        while(mid) {
            s1 += temp->val;
            s2 += mid->val;
            temp = temp->next;
            mid = mid->next;
        }
        reverse(s2.begin(), s2.end());
        if(s1 != s2) {
            return false;
        }
        else {
            return true;
        }
    }
};