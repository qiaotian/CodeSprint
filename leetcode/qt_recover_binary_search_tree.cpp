/**
* @Author: Tian Qiao
* @Date:   2016-07-28T13:24:33+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-28T13:24:40+08:00
* @Inc: unknown
* @Difficulty: Hard
*/


/**
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
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
 // a) 框架：中序遍历
 // b) 需要保留历史信息（firstNode, secondNode, preNode）
 // a) 框架：中序遍历
 // b) 需要保留历史信息（firstNode, secondNode, preNode）
 class Solution {
 private:
     TreeNode *firstNode = NULL;
     TreeNode *secondNode = NULL;
     TreeNode *preNode = new TreeNode(INT32_MIN);

 public:
     void traverse(TreeNode* root) {
         //找到两个节点就返回，不再遍历，不过这种思路错误，
         //因为secondNode在后续遍历过程中可能发生变化
         //secondNode的确定需要等待遍历整棵树以后才能确定
         //if(!root || (firstNode && secondNode)) return;

         if(!root) return;
         traverse(root->left);

         if(!firstNode && preNode->val>=root->val) firstNode = preNode;
         if(firstNode  && preNode->val>=root->val) secondNode = root;
         preNode = root;
         
         traverse(root->right);
     }
     void recoverTree(TreeNode* root) {
         // 1. find two nodes
         traverse(root);

         // 2. swap two nodes' values
         int tmp = firstNode->val;
         firstNode->val = secondNode->val;
         secondNode->val = tmp;
     }
 };
