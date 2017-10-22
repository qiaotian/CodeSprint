/*
ven a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* Sln 1
        vector<ListNode*> vec;
        ListNode* cur = head;
        while(cur) {
            vec.push_back(cur);
            cur = cur->next;
        }
        if(vec.size()==1) return NULL;
        if(n==1) {
            vec[vec.size()-2]->next = NULL;
            return head;
        }
        *vec[vec.size()-n] = *vec[vec.size()-n+1];
        return head;
        */
        /* Sln 2 */
        if(!head->next) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0; i<n; ++i){
            fast = fast->next;
        }
        if(fast==NULL) {
            // slow is nth element
            head = head->next;
        } else {
            while(fast->next){
                fast = fast->next;
                slow = slow->next;
            }
            // slow is the (n+1)th element
            if(slow->next) slow->next = slow->next->next; // slow->next is the nth elem
        }
        return head;
    }
};

/***
 * Sln 1 exchange time with space
 * /
