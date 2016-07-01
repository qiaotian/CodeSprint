/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-01T11:14:53+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-01T14:37:57+08:00
* @License: Free License
*/


/********
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree
          1
         / \
        2   3
       / \
      4   5
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:
          1
         /
        2
2. Now removing the leaf [2] would result in this tree:

          1
3. Now removing the leaf [1] would result in the empty tree:

          []
Returns [4, 5, 3], [2], [1].
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
    unordered_map<TreeNode*, int> hash; // map the node to its max distance to leaves
    int depth = 0; // max distance from root to nodes

    // mark every element with its depth and store them into dictionary
    void layering(TreeNode* root) {
        if(!root) return;

        if(!root->left && !root->right) {
            hash[root] = 0;
            return;
        } else if(root->left && !root->right) {
            layering(root->left);
            hash[root] = hash[root->left]+1;
        } else if(!root->left && root->right) {
            layering(root->right);
            hash[root] = hash[root->right]+1;
        } else {
            layering(root->left);
            layering(root->right);
            hash[root] = max(hash[root->left], hash[root->right])+1;
        }

        depth = hash[root];
    }
    // traverse all elements and put them into ans according to their depth
    void traverse(TreeNode* root, vector<vector<int>>& A) {
        if(!root) return;
        A[hash[root]].push_back(root->val);
        traverse(root->left, A);
        traverse(root->right, A);
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        layering(root);
        ans.resize(depth+1); // 改变ans的长度，注意depth的值
        traverse(root, ans);
        return ans;
    }
};


// sxycwzwzq's solution
// https://leetcode.com/discuss/110535/c-short-easy-understanding-dfs-solution
class Solution {
private:
    int dfs(TreeNode* root, vector<vector<int>>& res){
        if(!root) return 0;
        // 就算下一层节点距离叶节点的最远距离，从而确定当前层的层号
        int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        // 如果是新的一层，需要实例新的容器，再将当前节点压栈，否则直接压栈
        if(level > (int)res.size()) res.push_back(vector<int>());
        res[level - 1].push_back(root->val);
        // 返回当前层号
        return level;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
};
