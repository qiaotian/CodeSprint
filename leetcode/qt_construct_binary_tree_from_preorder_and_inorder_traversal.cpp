/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T18:48:51+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T20:09:46+08:00
* @Inc: Bloomberg
* @Difficulty: Medium
*/



/**
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
*/

// 问题：runtime error 死循环，原因在于 #1 处的前序和中序在递归过程中的下标范围写错

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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if(pl>pr || il>ir) return NULL;

        TreeNode *root = new TreeNode(preorder[pl]);
        if(pl==pr || il==ir) return root;

        int len = 0; //左子树长度
        while(inorder[len+il]!=preorder[pl]) len++;

        // # 1
        root->left = len<=0?NULL:helper(preorder, inorder, pl+1, pl+len, il, il+len-1);
        root->right = len>=(pr-pl)?NULL:helper(preorder, inorder, pl+len+1, pr, il+len+1, ir);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
