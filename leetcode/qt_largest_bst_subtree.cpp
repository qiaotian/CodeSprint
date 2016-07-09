/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T15:17:42+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-09T15:41:48+08:00
*/


/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \
 1   8   7
The Largest BST Subtree in this case is the highlighted one.
The return value is the subtree's size, which is 3.
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
    // return -1 if root is not bstTree
    // return n if root is bstTree and n is the number of nodes
    int bstTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int ll = bstTree(root->left);
        int rr = bstTree(root->right);

        if(ll>0 && rr==0) {
            if(root->val > root->left->val) return ll+1;
        }
        if(ll==0 && rr>0) {
            if(root->val < root->right->val) return rr+1;
        }
        if(ll>0 && rr>0) {
            if(root->val>root->left->val && root->val<root->right->val) return ll+rr+1;
        }

        return -1;
    }
    int largestBSTSubtree(TreeNode* root) {
        int re = bstTree(root);
        if(re<0) {
            int a = bstTree(root->left);
            int b = bstTree(root->right);
            if(a>0 || b>0) return max(a,b);
            return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
        }
        return re;
    }
};
