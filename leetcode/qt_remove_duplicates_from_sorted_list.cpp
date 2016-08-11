/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL)
            return head;
            
        //int value = head->val;
        ListNode * p = head->next, *pp = head;
        while(p!=NULL)
        {
            if(p->val == pp->val)
                pp->next = p->next;
            else
                pp=pp->next;
            p=p->next;
        }
        return head;
    }
};
