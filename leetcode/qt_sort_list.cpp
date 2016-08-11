/*
Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        
        ListNode *middleNode = getMiddleList(head);
        ListNode *nextNode = middleNode->next;
        middleNode->next = NULL;
        return mergeList(sortList(head), sortList(nextNode));
    }
    
    ListNode *getMiddleList(ListNode *head){
        ListNode *fast=head, *slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *mergeList(ListNode *first, ListNode *second){
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while(first!=NULL && second!=NULL){
            if(first->val <= second->val){
                if(head==NULL) {
                    head = first;
                    tail = first;
                    first=first->next;
                    tail->next = NULL;
                }
                else {
                    tail->next = first;
                    tail=tail->next;
                    first=first->next;
                    tail->next=NULL;
                }
            } 
            else {
                if(head==NULL) {
                    head = second;
                    tail = second;
                    second=second->next;
                    tail->next = NULL;
                }
                else {
                    tail->next =  second;
                    tail = tail->next;
                    second=second->next;
                    tail->next=NULL;
                }
            }
        }
        if(first!=NULL){
            if(head==NULL) {
                head = first;
            }
            else {
                tail->next = first;
                tail=tail->next;
            }
        }
        if(second!=NULL){
            if(head==NULL) {
                head = second;
            }
            else {
                tail->next = second;
                tail=tail->next;
            }
        }
        
        return head;
    }
};
