/**
* @Author: Tian Qiao
* @Date:   2016-08-07T22:51:58+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T22:52:10+08:00
* @Inc: Unknown
* @Tag: Tree BFS
*/

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> vecTree;
        vector<int> vecLayer;

        if(!root) return vecTree;

        int upstairs = 0; // the number of non-empty nodes in upper layer
        int currents = 0; // the number of non-empty nodes in current layer
        int count = 0; // the number of nodes have been scanned

        que.push(root);

        while(!que.empty()) {
            TreeNode* tmp = que.front();
            que.pop();
            count++;

            if(tmp) {
                que.push(tmp->left), que.push(tmp->right);
                vecLayer.push_back(tmp->val);
                currents++;
            }

            if(count == (upstairs==0?1:2*upstairs)) {
                if(vecLayer.size()) {
                    vector<int> cp(vecLayer); // make a copy
                    vecTree.insert(vecTree.begin(), cp);
                    vecLayer.clear();
                    upstairs = currents;
                    currents = 0;
                    count = 0;
                } else {
                    return vecTree; // all elements in current layer are empty nodes
                }
            }
        }
        return vecTree;
    }
};
