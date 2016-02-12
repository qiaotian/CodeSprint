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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        return ptrA;
    }
};

/****
 * Time: O(n)
 * ListA: S->A->A->O->A->E
 * ListB: S->O->A->E
 * 
 * S->A->A->O->A->E=>S->O->A->E
 * S->O->A->E=>S->A->A->O->A->E
 * /
