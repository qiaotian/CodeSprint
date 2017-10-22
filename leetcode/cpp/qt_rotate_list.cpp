/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 1st solution (8ms, beats 83.21%)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode *last = head;
        // get the amount of nodes
        int count = 1;
        while(last && last->next) {
            last = last->next;
            count++;
        }
        // 
        k = k % count;
        count = count - k;
        if(k == 0) return head;
        // 
        ListNode* nhead = head;
        while(--count) {
            nhead = nhead->next;
        }
        last->next = head;
        head = nhead->next;
        nhead->next = NULL;
        return head;
    }
};


/**
 * 1. find new head and new tail
 * 2. reconnect them
 * /
