/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-01T08:42:04+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-01T10:38:00+08:00
* @License: Free License
*/



/********
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
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
    ListNode* plusOne(ListNode* head) {
        //if(!head) return NULL;
        ListNode *h = new ListNode(0);
        h->next = head;

        ListNode *not9 = h; // 最后一位非9位
        ListNode *tmp = head;
        while(tmp) {
            if(tmp->val != 9) not9 = tmp;
            tmp = tmp->next;
        }

        not9->val++;
        while(not9->next) {
            not9->next->val=0;
            not9 = not9->next;
        }

        if(h->val==1) head = h;
        else delete h;

        return head;
    }
};

// 注意：
// 定义新节点的时候
// “ListNode *tmp = &ListNode(0);”会出错
// ”ListNode tmp(0); ListNode* h = &tmp; blabla; return h;”也会出错
