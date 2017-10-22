/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true; // the number of nodes is 0 or 1
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the post half part of the list
        slow->next = reverseList(slow->next); 
        // point the 'slow' to the first node of the post half part of the list
        slow = slow->next; 
        // compare the post half part with the former half part of the list
        ListNode* start = head;
        
        while(slow) {
            if(start->val != slow->val) return false;
            start = start->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* pre = NULL;
        ListNode* next = head->next;

        while(next) {
            head->next = pre;
            pre = head;
            head = next;
            next = next->next;
        }
        head->next = pre;
        return head;
    }
};

/**
 * Notice that before we use the node->next->next, we must make sure 
 * the existence of node and node->next
 * /
