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

// 与CloneGraph那道题不同之处在于
// Node的label在本题中可以相同，所以不能用label来区分节点，只能用节点地址（node指针）


// https://discuss.leetcode.com/topic/5831/2-clean-c-algorithms-without-using-extra-array-hash-table-algorithms-are-explained-step-by-step
// Here's how the 1st algorithm goes.
// Consider l1 as a node on the 1st list and l2 as the corresponding node on 2nd list.
// Step 1:
// Build the 2nd list by creating a new node for each node in 1st list.
// While doing so, insert each new node after it's corresponding node in the 1st list.
// Step 2:
// The new head is the 2nd node as that was the first inserted node.
// Step 3:
// Fix the random pointers in the 2nd list: (Remember that l1->next is actually l2)
// l2->random will be the node in 2nd list that corresponds l1->random,
// which is next node of l1->random.
// Step 4:
// Separate the combined list into 2: Splice out nodes that are part of second list.
// Return the new head that we saved in step 2.
//
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;

        for(RandomListNode* l1 = head; l1; l1=l1->next->next) {
            RandomListNode* tmp = new RandomListNode(l1->label);
            tmp->next = l1->next;
            l1->next = tmp;
        }

        for(RandomListNode* l1 = head; l1; l1=l1->next->next) {
            if(!l1->random) l1->next->random = NULL;
            else l1->next->random = l1->random->next;
        }

        RandomListNode *newHead = head->next;
        for(RandomListNode* l1 = head, *l2 = newHead; l1 && l2; l1 = l1->next, l2 = l2->next) {
            if(!l2->next) { l1->next = NULL; break; }
            l1->next = l1->next->next;
            l2->next = l1->next->next;
        }

        return newHead;
    }
};


// use hashtable
// https://discuss.leetcode.com/topic/10153/how-about-this-recursive-call-track-visited-node-with-hashtable
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> visitTable;//
        return copyRandomList(head, visitTable);
    }
private:
    RandomListNode *copyRandomList(RandomListNode *head, unordered_map<RandomListNode *, RandomListNode*> &visitTable) {
        if (!head) return head;
        if (visitTable.count(head)) return visitTable[head];
        RandomListNode *dup = new RandomListNode(head->label);
        visitTable[head] = dup;
        dup->next = copyRandomList(head->next, visitTable);
        dup->random = copyRandomList(head->random, visitTable);
        return dup;
    }
};
