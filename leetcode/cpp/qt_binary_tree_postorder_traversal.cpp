/**
* @Author: Tian Qiao
* @Date:   2016-08-07T22:58:34+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T22:58:37+08:00
* @Inc:
* @Difficulty: Hard
* @Tag: Stack, Tree
*/

/*
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
    void util(TreeNode* root, vector<int>& res) {
        if(!root) return;
        if(!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        if(root->left) util(root->left, res);
        if(root->right) util(root->right, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        util(root, res);
        return res;
    }
};
