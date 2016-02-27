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
private:
    vector<int> res;
    void helper(TreeNode* root, vector<TreeNode*>& stk) {
        // stk: stack
        TreeNode* ptr = root;
        while(ptr) {
            stk.push_back(ptr);
            ptr = ptr->left;
        }
        while(!stk.empty()) {
            TreeNode *parent = stk[stk.size()-1];
            stk.pop_back();
            res.push_back(parent->val);
            helper(parent->right, stk);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stk;
        helper(root, stk);
        return res;
    }
};
