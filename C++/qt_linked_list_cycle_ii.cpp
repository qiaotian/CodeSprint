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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next) return NULL;

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(1) {
            if(fast == slow) break;
            if(fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                return NULL;
            }
        }
        
        // redirect fast to start node
        // fast keeps same step with slow
        slow = head; 
        while(fast) {
            if(fast == slow) return fast;
            fast = fast->next; 
            slow = slow->next;
        }
        return NULL;
    }
};

/**
 * REFERENCE
 * https://leetcode.com/discuss/9908/o-n-solution-by-using-two-pointers-without-change-anything
 *   using two pointers, one of them one step at a time. another pointer each take two steps. Suppose the first meet at step k,the length of the Cycle is r. so..2k-k=nr,k=nr Now, the distance between the start node of list and the start node of cycle is s. the distance between the start of list and the first meeting node is k(the pointer which wake one step at a time waked k steps).the distance between the start node of cycle and the first meeting node is m, so...s=k-m, s=nr-m=(n-1)r+(r-m),here we takes n = 1..so, using one pointer start from the start node of list, another pointer start from the first meeting node, all of them wake one step at a time, the first time they meeting each other is the start of the cycle.
 * 
 * /
