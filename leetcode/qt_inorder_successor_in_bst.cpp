/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T23:39:36+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-10T00:09:45+08:00
* @Inc: MS, Facebook
*/



/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
Note: If the given node has no in-order successor in the tree, return null.
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
     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
         TreeNode* succ = NULL;
         while(root) {
             if(root->val>p->val) {
                 succ = root;
                 root = root->left;
             } else {
                 root = root->right;
             }
         }
         return succ;
     }
 };
