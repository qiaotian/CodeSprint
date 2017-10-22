/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var head = null;
    var cur = null;
    var carry = 0, a, b, c;
    while (l1 != null || l2 != null) {
        a = (l1 == null)?0:l1.val;
        b = (l2 == null)?0:l2.val;
        c = a + b + carry;
        carry = Math.floor(c/10);
        var tmp = new ListNode(c%10)
        if (head == null) {
            head = tmp;
            cur = tmp;
        } else {
            cur.next = tmp;
            cur = tmp;
        }
        if (l1 != null) l1 = l1.next;
        if (l2 != null) l2 = l2.next;
    }
    if (carry > 0) {
        cur.next = new ListNode(carry);
    }
    return head;
};
