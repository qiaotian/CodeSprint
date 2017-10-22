/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 1st solution
class Solution {
    int util(TreeNode* root, int& res) {
        // 以root为树，经过root的最大和，root的父节点不考虑
        int sum;
        if(!root) {
            sum = 0;
            res = max(res, 0);
            return sum;
        }
        if(!root->left && !root->right) {
            sum = root->val;
            res = max(res, root->val);
            return sum;
        }
        if(!root->left && root->right) {
            sum = max(util(root->right, res), 0) + root->val;
            res = max(res, sum);
            return sum;
        }
        if(root->left && !root->right) {
            sum = max(util(root->left, res), 0) + root->val;
            res = max(res, sum);
            return sum;
        } else {
            int left = max(0, util(root->left, res));
            int right = max(0, util(root->right, res));
            sum = max(left, right) + root->val;
            res = max(res, max(0, left)+max(0, right) + root->val);
            return sum;
        }
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT32_MIN;
        util(root, res);
        return res;
    }
};

// 2nd solution
class Solution {
    int maxToRoot(TreeNode *root, int &re) {
        if (!root) return 0;
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        if (l + r + root->val > re) re = l + r + root->val;
        return root->val += max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = -2147483648;
        maxToRoot(root, max);
        return max;
    }
};

/**
 * WARNING
 * 1. 递归计算“当前节点”到其所有叶子节点的最大和min
 * 2. 更新通过“当前节点”的所有路径的最大和res
 * 3. 两种算法的时间复杂度一致，只是第二种更为简洁
 * 
 * /