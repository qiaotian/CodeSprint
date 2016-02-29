/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* start, ListNode* end) {
        // 负责head 到 end之间的所有节点反转并返回第一个节点
        // 维护“end的next”这两个指针
        if(!start || !start->next || start == end) return start;
        
        ListNode *tmp = end->next;
        ListNode* node = reverseList(start->next, end);
        start->next->next = start;
        start->next = tmp;
        return node;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;

        ListNode* cur = head;
        ListNode* pre = head;
        ListNode* end = head;
        
        int i = 1;
        while(cur) {
            if(i == m-1) pre = cur;
            if(i == n) end = cur;
            cur = cur->next;
            i++;
        }
        if(m == 1) head = reverseList(head, end);
        else pre->next = reverseList(pre->next, end);
        return head;
    }
};

// recursive

class Solution {  
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        for (int i = 0; i < m - 1; i++)
            pre = pre -> next;
        ListNode* cur = pre -> next;
        for (int i = 0; i < n - m; i++) {
            ListNode* move = cur -> next; 
            cur -> next = move -> next;
            move -> next = pre -> next;
            pre -> next = move;
        }
        return new_head -> next;
    }
}; 
