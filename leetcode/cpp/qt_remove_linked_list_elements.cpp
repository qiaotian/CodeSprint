/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/**
 * Low efficient
 * Solution one: beat only 11% cpp submission
 * 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // return empty if link has no node
        if(!head) {
            return head;
        }
        // find the first "nonval" node and point head to it
        while(head->val == val) {
            head = head->next;
            if(!head) return head;
        }
        
        // init pre and current
        ListNode *pre = head;
        ListNode *current = head->next;
        
        // delete the node whose val is equal to given val
        while(current) {
            if(current->val == val) {
                current = current->next;
                pre->next = current;
            } else {
                current = current->next;
                pre = pre->next;
            }
        }
        return head;
    }
};
*/
/**
 * Low efficient
 * Solution one: beat only 11% cpp submission
 * 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode tem(0);
        ListNode *temp = &tem;
        temp->next = head;
        head = temp;
        ListNode *current = head->next;
        ListNode *pre = temp;
        while(current){
            if(current->val==val){
                pre->next = current->next;
                current = current->next;
            } else {
                pre = pre->next;
                current = current->next;
            }
        }
        return head->next;
    }
};
*/

/**
 * Low efficient
 * Solution one: beat only 11% cpp submission
 * 
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head==NULL) return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pseudo_head = new ListNode(0);
        pseudo_head->next = head;
        ListNode *cur = pseudo_head;
        while(cur){
            if(cur->next && cur->next->val == val)   cur->next = cur->next->next;
            else    cur = cur->next;
        }
        return pseudo_head->next;
    }
};
