/**
* @Author: Tian Qiao
* @Date:   2016-07-24T14:10:10+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-24T14:10:27+08:00
* @Inc: MS, FB
* @Difficulty: Hard
*/

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/


 // 指针操作=易错
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
    // first: the first node of enitre section to be reversed
    // last: the next to the last node of entire section to be reversed
    ListNode* reverse(ListNode* first, ListNode* last) {
        ListNode* prev = last;
        while (first != last) {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node = head;
        // it's confusing until finding out the
        // trick that putting "!node" before "update node"
        for (int i=0; i < k; ++i) {
            if (!node) return head; // do nothing as list is too sort
            node = node->next;
        }

        auto new_head = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return new_head;
    }
};


//
/*
-1 -> 1 -> 2 -> 3 -> 4 -> 5
 |    |    |
pre  cur  nex

-1 -> 2 -> 1 -> 3 -> 4 -> 5
 |         |    |
pre       cur  nex

-1 -> 3 -> 2 -> 1 -> 4 -> 5
 |              |    |
pre            cur  nex
*/

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *nex, *pre = dummy;//pay attention to the star *
        while(cur = cur->next) num++; // calculate the number of nodes
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            //依次将大数插到前面.当k=4,
            //1234->2134->3214->4321
            //因此需要k-1次
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return dummy->next;
    }
};
