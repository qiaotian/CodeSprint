//For the example list 1 -> 2 -> 3 -> 4 -> 5 in the problem statement, it will become 0 -> 1 -> 2 -> 3 -> 4 -> 5 (we init new_head -> val to be 0). Then we set a pointer pre to new_head and another cur to head. Then we keep inserting cur -> next after pre until cur becomes the last node. The code is follows.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head; 
        while (cur && cur -> next) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next; 
            pre -> next -> next = temp;
        }
        return new_head -> next;
    }
};

// This link provides a more concise solution without using the new_head. The idea is to reverse one node at a time for the beginning of the list. The rewritten code is as follows.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        } 
        return pre;
    }
};

// Well, both of the above solutions are iterative. The hint has also suggested us to use recursion. In fact, the above link has a nice recursive solution, whose rewritten code is as follows.

class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
};
