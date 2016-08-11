/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
// 非递归 
/*
class Solution {
private:
    stack<TreeNode*> mstack;
    void helper(TreeNode* root, int& ret, int &curr) {
        // root: 当前根节点
        // curr: 当前根节点之前的路径之和
        if(!root) return;

        TreeNode* ptr = root;
        while(ptr) {
            mstack.push(ptr);
            curr = curr*10 + ptr->val;
            ptr = ptr->left;
        }
        while(!mstack.empty()) {
            TreeNode* ptr = mstack.top();
            mstack.pop();
            if(!ptr->left && !ptr->right) ret = ret + curr;
            if(ptr->right) {
                ptr = ptr->right;
                while(ptr) mstack.push(ptr);
            }
            curr /= 10;
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int curr = 0;
        helper(root, res, curr);
        return res;
    }
};*/

class Solution {
public:
    int util(TreeNode* root, int x) {
        int res = 0;
        if(!root->left && !root->right) return x * 10 + root->val;
        if(root->left) res += util(root->left, x * 10 + root->val);
        if(root->right) res += util(root->right, x * 10 + root->val);
        return res;
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return util(root, 0);
    }
};
