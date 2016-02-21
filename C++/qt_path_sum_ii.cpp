/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 1st solution (16ms, beats 42%)
class Solution {
private:
    vector<vector<int>> res;
    void helper(TreeNode* root, vector<int>& path, int sum) {
        if(!root->left && !root->right) {
            // root is leaf node
            if(root->val == sum) {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(root->val);
        if(root->left) findPath(root->left, path, sum - root->val);
        if(root->right) findPath(root->right, path, sum - root->val);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return res;
        vector<int> path;
        helper(root, path, sum);
        return res;
    }
};

/**
 * WARNING
 * The node value could be negative, so we don't need pruning when root value is bigger than sum.
 * 
 * 1st solution (DFS)
 * /
