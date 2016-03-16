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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *nhead = new ListNode(-1);
        nhead->next = head;

        ListNode *cur = head;
        ListNode *pre = nhead;
        while(cur->next) {
            // skip non-duplicated elements
            if(cur->val != cur->next->val) {
                pre = cur;
                cur = cur->next;
                continue;
            }
            // delete the duplicated elements
            while(cur->val == cur->next->val) {
                cur = cur->next;
                if(!cur->next) {
                    pre->next = NULL;
                    head = nhead->next;
                    delete nhead;
                    return head;
                }
            }
            pre->next = cur->next; // delete
            cur = cur->next;
        }
        return nhead->next;
    }
};
