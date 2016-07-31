/**
* @Author: Tian Qiao
* @Date:   2016-07-30T22:01:37+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-30T22:01:38+08:00
* @Inc: Bloomberg
* @Difficulty: Easy
*/

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    // 1st Solution
    /*
    int treeDepth(TreeNode* root) {
        if(!root) return 0;
        return max(treeDepth(root->left), treeDepth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        // 1st Solution
        if(!root) return true;

        //if(abs(treeDepth(root->left)-treeDepth(root->right))<2) {
            //  return isBalanced(root->left) && isBalanced(root->right);
        //} else {
            //  return false;
        //}
        return abs(treeDepth(root->left)-treeDepth(root->right))<2 &&\
               isBalanced(root->left) &&\
               isBalanced(root->right);
    }
    */

    // 2nd Solution
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;

        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }
};

/**
 * 1st Solution (16ms)
 * Recursion
 *
 * 2nd Solution (8ms)
 * DFS
 * /
