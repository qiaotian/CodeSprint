/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-08T13:52:12+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-08T15:31:53+08:00
*/



Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.



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
    ListNode* revertList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* rhead = NULL;
        while(head) {
            // 取节点
            ListNode *tmp = head;
            head = head->next;
            tmp->next = NULL;
            // 插入节点
            tmp->next = rhead;
            rhead = tmp;
        }
        return rhead;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* increase = head;
        ListNode* decrease = head;
        while(increase && increase->next &&increase->next->next) {
            decrease = decrease->next;
            increase = increase->next->next;
        }

        increase = head;
        ListNode* pre = decrease;
        decrease = decrease->next;
        pre->next = NULL; // seperate the origin list into two lists

        decrease = revertList(decrease);

        // insert all decrease nodes into increase sequences
        ListNode* tmpIncrease = increase;
        while(tmpIncrease && decrease) {
            // 从decrease头部取出一个节点
            ListNode *tmp = decrease;
            decrease = decrease->next;
            tmp->next = NULL;

            // 将该节点插入tmpIncrease后面
            ListNode *post = tmpIncrease->next;
            tmpIncrease->next = tmp;
            tmp->next = post;
            tmpIncrease = tmpIncrease->next->next;
        }
        head = increase;
    }
};

// (耗时30mins) 将指针作为参数传入，如果在函数中修改该指针，一旦离开函数作用域，指针修改失效。
// 因此，规范操作仍然是将修改指针返回，或者使用指针的引用。
