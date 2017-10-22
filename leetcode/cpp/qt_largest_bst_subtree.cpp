/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T15:17:42+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-09T20:26:03+08:00
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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        // 以root为根的树的最大值和最小值
        int mini, maxi;
        isBST(root, res, mini, maxi);
        return res;
    }
    
    // BST要求Root大于左子树的所有节点值，并且小于右子树的所有节点值
    bool isBST(TreeNode* root, int& count, int& mini, int& maxi) {
        // count: 以root为根节点的子树中最大bst子树的节点数
        // mini:  最大bst的最小值
        // maxi:  最大bst的最大值
        if (!root) return true;
        
        int lsize = 0, rsize = 0; // 左右子树的最大bst尺寸
        int lmin, lmax, rmin, rmax; // 左右子树的最大bst的最小最大值
        
        bool ll = isBST(root->left, lsize, lmin, lmax);
        bool rr = isBST(root->right, rsize, rmin, rmax);

        if (ll && rr && (!root->left || root->val>=lmax) && (!root->right || root->val<=rmin) ) {
            // 以node为根的树为bst（左右子树都是bst，切满足bst的大小关系）
            count  = lsize+rsize+1;
            mini = root->left?lmin:root->val;
            maxi = root->right?rmax:root->val;
            return true;
        } else {
            // 以node为根的树并非节点树，因此最终的最大节点数为左子树或者右子树的最大节点数
            count = max(lsize, rsize);
            return false;
        }
    }
};
