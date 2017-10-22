/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T23:39:36+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-10T00:30:48+08:00
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

 // p的后继节点值一定大于p的值，因此更新succ时只要新节点的值大于p的值，即可将succ指向该节点



class Solution {
public:
     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root==NULL || p==NULL) { return NULL; }
        if (p.right != NULL) {  // first try to find it in p's right subtree
            TreeNode* q = p->right;
            while (q->left!=NULL) { q = q->left; }
            return q;
        }  // if not found, next go upwards
        TreeNode* succ = dfs(root, p);
        return succ==p ? NULL : succ;
    }

    TreeNode* dfs(TreeNode* node, TreeNode* p) {
        if (node==NULL || node==p) { return node; }
        TreeNode* left = dfs(node->left, p);
        TreeNode* right = dfs(node->right, p);
        if (right == p) { return p; }
        if (left == p) { return node; }
        return left?left:right;
    }
}
