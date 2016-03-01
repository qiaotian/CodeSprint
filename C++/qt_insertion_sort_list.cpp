/**
 * For God's sake, don't try sorting a linked list during the interview
 * http://steve-yegge.blogspot.nl/2008/03/get-that-job-at-google.html
 * 
 * /
 * 
 * 
 * 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 1st solution (100ms, beats 9%) 
/*
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *mhead = head;
        head = head->next;
        mhead->next = NULL;

        while(head) {
            // get new node to be inserted
            ListNode* node = head;
            head = head->next; 
            node->next = NULL;
            // insert the new node to new list
            ListNode* curr = mhead;
            ListNode* pre = mhead;

            while(curr) {
                if(node->val <= curr->val) {
                    // insert node before curr node
                    node->next = curr;
                    if(curr == mhead) mhead = node;
                    else pre->next = node;
                    // finished current insertion and stop
                    break; 
                } else {
                    // move curr to next node
                    if(!curr->next) {
                        // curr is the last node of the link
                        // insert node after curr
                        curr->next = node;
                        // finished current insertion and stop
                        break;
                    } else {
                        if(pre != curr) pre = pre->next;
                        curr = curr->next;
                    }
                }
            }
        }
        return mhead;
    }
};
*/

//  First, a quick recap of insertion sort:Start from the second element (simply a[1] in array and the annoying head -> next -> val in linked list), each time when we see a node with val smaller than its previous node, we scan from the head and find the position that the current node should be inserted. Since a node may be inserted before head, we create a new_head that points to head. The insertion operation, however, is a little easier for linked list.

class Solution { 
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) {
            if (cur -> next && cur -> next -> val < cur -> val) {
                while (pre -> next && pre -> next -> val < cur -> next -> val)
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = new_head;
            }
            else cur = cur -> next;
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};
