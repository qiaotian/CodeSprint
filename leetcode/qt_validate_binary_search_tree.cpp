/**
* @Author: Tian Qiao
* @Date:   2016-07-14T00:13:37+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-14T00:14:05+08:00
* @Inc: Amazon, Facebook, Microsoft, Bloomberg
*/



/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

 // This solution cannot solve the test case:[-2147483648,null,2147483647]
 /*
 class Solution {
 public:
     bool helper(TreeNode* root, int& l, int& r) {
         // l是整棵树最小值
         // r是整棵树最大值
         l = INT32_MAX, r = INT32_MIN;
         if(!root) return true;

         l = min(l, root->val), r = max(r, root->val);
         if(!root->left && !root->right) return true;

         int ll, lr, rl, rr;
         bool isBSTL = helper(root->left, ll, lr);
         bool isBSTR = helper(root->right, rl, rr);

         l = min(ll, min(l, rl));
         r = max(rr, max(r, rr));

         if(root->val > lr && root->val < rl) return isBSTL && isBSTR;
         else return false;
     }
     bool isValidBST(TreeNode* root) {
         if(!root) return true;
         int left = 0, right = 0;
         return helper(root, left, right);
     }
 };
 */
 class Solution {
 public:
     bool isValidBST(TreeNode* root) {
         return isValidBST(root, NULL, NULL);
     }
     // 虽然root节点既不是左子树，也不是右子树上的节点
     // 但是是可以将root作为左子树的最大界，右子树的最下界
     bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
         if(!root) return true;
         if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val) return false;
         return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
     }
 };
