/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        
        // find the middle element
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *slow_pre = head;

        while(fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow_pre->next->next == slow) slow_pre = slow_pre->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);
        if(slow == fast) {
            // 节点数少于3
            head = NULL;
        } else {
            slow_pre->next = NULL;
        }
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
