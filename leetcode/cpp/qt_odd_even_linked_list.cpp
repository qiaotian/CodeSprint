/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        /*
        ListNode* cur = head;
        
        bool sorted = false;
        while(!sorted) {
            // group once
            while(cur) {
                if(cur->next) {
                    if(cur->val%2==0 && cur->next->val%2==1) {
                        int tmp = cur->val;
                        cur->val = cur->next->val;
                        cur->next->val = tmp;
                    }
                }
                cur = cur->next;
            }
            
            // check if group completed
            cur = head;
            sorted = true;
            while(cur && cur->next) {
                if(cur->val%2==0 && cur->next->val%2==1) {
                    sorted = false;
                    break;
                }
                cur = cur->next;
            }
        }
        return head;
        */
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* even = next;
        bool odd = true; // current node is odd node
        while(next->next) {
            curr->next = next->next;
            curr = next;
            odd = !odd; // change current node to oposite
            next = next->next;
        }
        curr->next = NULL;
        if (odd) curr->next = even;
        else next->next = even;
        return head;
    }
};

/**
 * NOTICE
 * The question should be reconsidered!
 * Don't mistake the target!
 * 
 * /
