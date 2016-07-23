/**
* @Author: Tian Qiao
* @Date:   2016-07-23T01:47:07+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-23T01:47:32+08:00
* @Inc: Uber, Bloomberg, Amazon, Microsoft
* @Difficulty: Hard
*/


/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
*/


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *hh = NULL;
        if(!head) return hh;

        int index = 0;
        //unordered_map<int, RandomListNode*> dict; // map index to its random node
        unordered_map<RandomListNode*, RandomListNode*> dict；
        chead = new RandomListNode(head->label);
        dict[head] = chead;

        RandomListNode *pre = chead; //新链表的pre节点
        RandomListNode *cur = head->next; //旧链表的当前节点
        while(cur) {
            RandomListNode *tmp = new RandomListNode(cur->label);
            dict[cur] = tmp;
            pre->next = tmp;
            pre = pre->next;
            cur = cur->next;
        }

        RandomListNode* fly1 = head;
        RandomListNode* fly2 = chead;
        while(fly1) {
            fly2->random = dict[fly1->ramdom];
            fly1 = fly1->next;
            fly2 = fly2->next;
        }

        return chead;
    }
};
