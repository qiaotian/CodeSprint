/**
* @Author: Tian Qiao
* @Date:   2016-08-07T22:56:01+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T22:56:05+08:00
* @Inc: Google, Facebook, Apple
* @Difficulty: Easy
* @Tag: Tree, DFS
*/


/*
Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:
["1->2->5", "1->3"]
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
    void utility(vector<string> &vec, TreeNode* root, string tmp) {
        // 'tmp' string already contain the root value
        // if root has no child, we can push tmp into vector directly
        if(!root->left && !root->right) {
            vec.push_back(tmp);
            return;
        }
        if(root->left) utility(vec, root->left, tmp+"->"+to_string(root->left->val));
        if(root->right) utility(vec, root->right, tmp+"->"+to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        string t = to_string(root->val);
        utility(res, root, t);
        return res;
    }
};
