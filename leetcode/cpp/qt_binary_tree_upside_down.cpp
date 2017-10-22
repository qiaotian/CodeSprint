/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T23:46:38+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-07T01:33:48+08:00
* @Inc: LinkedIn
*/



Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1




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
     TreeNode* upsideDownBinaryTree(TreeNode* root) {
         if (!root || !root->left) return root;
         TreeNode* cur_left = root->left;
         TreeNode* cur_right = root->right;
         TreeNode* new_root = upsideDownBinaryTree(root->left);
         cur_left->right = root;
         cur_left->left = cur_right;
         root->left = nullptr;
         root->right = nullptr;
         return new_root;
     }
 };
