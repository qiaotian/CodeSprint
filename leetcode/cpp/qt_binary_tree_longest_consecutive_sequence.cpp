/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T11:51:45+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-09T20:25:58+08:00
* @Inc: Google
*/

/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    /
   2
  /
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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

 /*
class Solution {
public:
   int longestConsecutive(TreeNode* root) {
       if(!root) return 0;
       if(!root->left && !root->right) return 1; //此时返回值应与parent有关，不能直接

       int ans = 0;
       if(root->left) {
           if(root->left->val==root->val+1)
               ans = max(ans, 1+longestConsecutive(root->left));
           else
               ans = max(ans, longestConsecutive(root->left));
       }
       if(root->right) {
           if(root->right->val==root->val+1)
               ans = max(ans, 1+longestConsecutive(root->right));
           else
               ans = max(ans, longestConsecutive(root->right));
       }
       return ans;
   }
};
*/
class Solution {
public:
    int helper(TreeNode* root, TreeNode* parent, int len) {
        if(!root) return len;
        len = (parent && parent->val+1==root->val)?1+len:1;
        return max(len, max(helper(root->left, root, len), helper(root->right, root, len)));
    }
    int longestConsecutive(TreeNode* root) {
        return helper(root, NULL, 0);
    }
};
