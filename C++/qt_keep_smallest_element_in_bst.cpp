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
    vector<TreeNode*> stk; // stack
    bool helper(TreeNode* root, int& k, int& res) {
        // found return true, otherwise return false
        TreeNode* ptr = root;
        while(ptr) {
            stk.push_back(ptr);
            ptr = ptr->left;
        }
        while(!stk.empty()) {
            TreeNode* parent = stk[stk.size()-1];
            stk.pop_back();
            if(--k == 0) {
                res = parent->val;
                return true;
            }
            if(helper(parent->right, k, res)) return true;
        }
        return false;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        helper(root, k, res);
        return res;
    }
};

/**
 * WARNING
 * 1. right: helper(TreeNode* root, int& k, int& res)
 * 2. wrong: helper(TreeNode* root, int  k, int  res)
 * 
 * In second function, the 'k' is a value equals 'k' 
 * but stored in another address, therefore the k didn't
 * change outside the fuction helper, so does 'res'.
 * 
 * /
