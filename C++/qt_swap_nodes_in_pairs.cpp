/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* cur = head;
        ListNode* nxt = head->next;

        head = nxt;
        cur->next = nxt->next;
        nxt->next = cur;
        
        ListNode* pre = cur;
        while(pre->next && pre->next->next) {
            cur = pre->next;
            nxt = pre->next->next;
            
            cur->next = nxt->next;
            nxt->next = cur;
            pre->next = nxt;
            
            pre = cur;
        }
        return head;
    }
};
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* nxt = head->next;
        head->next = swapPairs(nxt->next);
        nxt->next = head;
        return nxt;
    }
};
