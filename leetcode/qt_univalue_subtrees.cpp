/**
* @Author: Tian Qiao
* @Date:   2016-07-05T16:19:54+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-05T16:56:45+08:00
*/


/*

Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.
For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.

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
    int ans = 0;
    bool isUnivalSubtree(TreeNode* root) {
        if(!root) return true;
        bool ll = isUnivalSubtree(root->left);
        bool rr = isUnivalSubtree(root->right);
        // 以下写法错误，因为第一个条件不满足条件，后面的条件将直接跳过
        // 不再执行，那么统计ans的时候就会有遗漏
        /*
        bool isUnival = isUnivalSubtree(root->left) &&\
                        isUnivalSubtree(root->right) &&\
                        (root->val == (root->left?root->left->val:root->val)) &&\
                        (root->val == (root->right?root->right->val:root->val));
        */
        bool isUnival = ll && rr &&\
                        (root->val == (root->left?root->left->val:root->val)) &&\
                        (root->val == (root->right?root->right->val:root->val));

        if(isUnival) ans++;
        return isUnival;
    }
    int countUnivalSubtrees(TreeNode* root) {
        isUnivalSubtree(root);
        return ans;
    }
};
