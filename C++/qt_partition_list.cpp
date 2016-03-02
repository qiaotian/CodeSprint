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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        
        ListNode* head1 = NULL; // head of list whose nodes value are less than x
        ListNode* head2 = NULL;
        ListNode* tail1 = NULL; // tail of list whose nodes value are less than x
        ListNode* tail2 = NULL;
        ListNode* ptr = head;
        while(ptr) {
            if(ptr->val < x) {
                if(!head1) { 
                    head1 = ptr; 
                    tail1 = ptr;
                } else {
                    tail1->next = ptr;
                    tail1 = tail1->next;
                }
            } else {
                if(!head2) { 
                    head2 = ptr; 
                    tail2 = ptr;
                } else {
                    tail2->next = ptr;
                    tail2 = tail2->next;
                }
            } 
            ptr = ptr->next;
        }
        if(!head1) return head2;
        if(!head2) return head1;
        head = head1;
        tail1->next = head2;
        tail2->next = NULL;
        return head;
    }
};

// 使用两个链表，分别连接小于x的所有节点和大于等于x的所有节点

