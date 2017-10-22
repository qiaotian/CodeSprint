/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T15:38:27+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T15:39:56+08:00
* @Inc: Microsoft
* @Difficulty: Easy
*/



_______________________________________________________________________________

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
_______________________________________________________________________________

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false; // we can not return 0 if there's no nodes available
        if(!root->left && !root->right) return root->val == sum;
        if(root->left && hasPathSum(root->left, sum-root->val)) return true;
        if(root->right && hasPathSum(root->right, sum-root->val)) return true;
    }
};
/***
 *
 * /
