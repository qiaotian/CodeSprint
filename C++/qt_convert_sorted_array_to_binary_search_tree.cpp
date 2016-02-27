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
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(nums[(start+end)/2]);
        if(start == end) return root;
        root->left = helper(nums, start, (start+end)/2-1);
        root->right = helper(nums, (start+end)/2+1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};
