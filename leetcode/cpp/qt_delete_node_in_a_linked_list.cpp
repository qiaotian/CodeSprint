/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:38:47+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:38:49+08:00
* @Inc: Adobe, Apple, Facebook
* @Tag: LinkedList
* @Difficulty: Easy
*/

/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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
    void deleteNode(ListNode* node) {
        // Sln 1
        //ListNode *temp = node;
        //node->next = temp->next;
        //delete temp;
        // Wrong
        // Sln 2
        auto next = node->next;
        *node = *next;
        delete next;

        /* // Sln 3
        *node = *node->next;
        */
    }
};

// NOTICE
// The target is to delete the current node called 'node' and no previous node available,
// therefore copying the next node to current node is the only solution.
